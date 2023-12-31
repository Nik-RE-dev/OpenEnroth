#include "EngineTraceStateAccessor.h"

#include <string>

#include "Application/GameConfig.h"

#include "Engine/Party.h"
#include "Engine/mm7_data.h"

#include "Media/Audio/AudioPlayer.h"

#include "Library/Trace/EventTrace.h"

#include "Utility/String.h"

static bool shouldSkip(const GameConfig *config, const ConfigSection *section, const AnyConfigEntry *entry) {
    return
        (section == &config->window && entry != &config->window.Width && entry != &config->window.Height) ||
        section == &config->graphics ||
        entry == &config->settings.MusicLevel ||
        entry == &config->settings.VoiceLevel ||
        entry == &config->settings.SoundLevel ||
        entry == &config->debug.LogLevel ||
        entry == &config->debug.NoVideo ||
        entry == &config->gameplay.QuickSavesCount;
}

static bool shouldTake(const GameConfig *config, const ConfigSection *section, const AnyConfigEntry *entry) {
    return
        entry->string() != entry->defaultString() ||
        entry == &config->debug.TraceFrameTimeMs ||
        entry == &config->debug.TraceRandomEngine ||
        entry == &config->debug.TraceNoVideo;
}

void EngineTraceStateAccessor::prepareForRecording(GameConfig *config, ConfigPatch *patch) {
    *patch = ConfigPatch::fromConfig(config, [config] (const ConfigSection *section, const AnyConfigEntry *entry) {
        return !shouldSkip(config, section, entry) && shouldTake(config, section, entry);
    });

    config->graphics.FPSLimit.setValue(1000 / config->debug.TraceFrameTimeMs.value());
    config->debug.NoVideo.setValue(config->debug.TraceNoVideo.value());
}

void EngineTraceStateAccessor::prepareForPlayback(GameConfig *config, const ConfigPatch &patch) {
    for (ConfigSection *section : config->sections())
        for (AnyConfigEntry *entry : section->entries())
            if (!shouldSkip(config, section, entry))
                entry->reset();

    // TODO(captainurist): Right now setting keybindings here doesn't work
    patch.apply(config);

    config->settings.MusicLevel.setValue(0);
    config->settings.VoiceLevel.setValue(0);
    config->settings.SoundLevel.setValue(0);
    config->window.MouseGrab.setValue(false);
    config->graphics.FPSLimit.setValue(0); // Unlimited
    config->debug.NoVideo.setValue(config->debug.TraceNoVideo.value());
    pAudioPlayer->UpdateVolumeFromConfig();
}

EventTraceGameState EngineTraceStateAccessor::makeGameState() {
    EventTraceGameState result;
    result.locationName = toLower(pCurrentMapName);
    result.partyPosition = pParty->pos.toInt();
    return result;
}
