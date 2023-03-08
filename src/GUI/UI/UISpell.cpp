#include "UISpell.h"
#include "UIStatusBar.h"

#include "GUI/GUIButton.h"

#include "Media/Audio/AudioPlayer.h"

#include "Engine/Spells/CastSpellInfo.h"
#include "Engine/Localization.h"

TargetedSpellUI::TargetedSpellUI(Pointi position, Sizei dimensions, WindowData data, const std::string &hint)
    : GUIWindow(WINDOW_CastSpell, position, dimensions, data, hint) {
    pEventTimer->Pause();
    pAudioPlayer->PauseSounds(-1);
    mouse->SetCursorImage("MICON2");
    GameUI_SetStatusBar(LSTR_CHOOSE_TARGET);
}

TargetedSpellUI_Hirelings::TargetedSpellUI_Hirelings(Pointi position, Sizei dimensions, WindowData data, const std::string &hint)
    : TargetedSpellUI(position, dimensions, data, hint) {
    pBtn_NPCLeft = CreateButton({469, 178}, {ui_btn_npc_left->GetWidth(), ui_btn_npc_left->GetHeight()},
            1, 0, UIMSG_ScrollNPCPanel, 0, InputAction::Invalid, "", {ui_btn_npc_left});
    pBtn_NPCRight = CreateButton({626, 178}, {ui_btn_npc_right->GetWidth(), ui_btn_npc_right->GetHeight()},
            1, 0, UIMSG_ScrollNPCPanel, 1, InputAction::Invalid, "", {ui_btn_npc_right});
    CreateButton({491, 149}, {64, 74}, 1, 0, UIMSG_HiredNPC_CastSpell, 4, InputAction::SelectNPC1);
    CreateButton({561, 149}, {64, 74}, 1, 0, UIMSG_HiredNPC_CastSpell, 5, InputAction::SelectNPC2);
}

TargetedSpellUI_Character::TargetedSpellUI_Character(Pointi position, Sizei dimensions, WindowData data, const std::string &hint)
    : TargetedSpellUI(position, dimensions, data, hint) {
    CreateButton({52, 422}, {35, 0}, 2, 0, UIMSG_CastSpell_Character_Big_Improvement, 0, InputAction::SelectChar1);
    CreateButton({165, 422}, {35, 0}, 2, 0, UIMSG_CastSpell_Character_Big_Improvement, 1, InputAction::SelectChar2);
    CreateButton({280, 422}, {35, 0}, 2, 0, UIMSG_CastSpell_Character_Big_Improvement, 2, InputAction::SelectChar3);
    CreateButton({390, 422}, {35, 0}, 2, 0, UIMSG_CastSpell_Character_Big_Improvement, 3, InputAction::SelectChar4);
}

TargetedSpellUI_Actor::TargetedSpellUI_Actor(Pointi position, Sizei dimensions, WindowData data, const std::string &hint)
    : TargetedSpellUI(position, dimensions, data, hint) {
    CreateButton({game_viewport_x, game_viewport_y}, {game_viewport_width, game_viewport_height}, 1, 0, UIMSG_CastSpell_Shoot_Monster, 0);
}

TargetedSpellUI_ActorOrCharacter::TargetedSpellUI_ActorOrCharacter(Pointi position, Sizei dimensions, WindowData data, const std::string &hint)
    : TargetedSpellUI(position, dimensions, data, hint) {
    CreateButton({52, 422}, {35, 0}, 2, 0, UIMSG_CastSpell_Character_Small_Improvement, 0, InputAction::SelectChar1);
    CreateButton({165, 422}, {35, 0}, 2, 0, UIMSG_CastSpell_Character_Small_Improvement, 1, InputAction::SelectChar2);
    CreateButton({280, 422}, {35, 0}, 2, 0, UIMSG_CastSpell_Character_Small_Improvement, 2, InputAction::SelectChar3);
    CreateButton({390, 422}, {35, 0}, 2, 0, UIMSG_CastSpell_Character_Small_Improvement, 3, InputAction::SelectChar4);
    CreateButton({8, 8}, {game_viewport_width, game_viewport_height}, 1, 0, UIMSG_CastSpell_Monster_Improvement, 0);
}

TargetedSpellUI_Telekenesis::TargetedSpellUI_Telekenesis(Pointi position, Sizei dimensions, WindowData data, const std::string &hint)
    : TargetedSpellUI(position, dimensions, data, hint) {
    CreateButton({game_viewport_x, game_viewport_y}, {game_viewport_width, game_viewport_height}, 1, 0, UIMSG_CastSpell_Telekinesis, 0);
}
