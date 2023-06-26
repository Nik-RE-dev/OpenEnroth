#pragma once

#include <array>
#include <string>
#include <vector>

#include "Utility/Memory/Blob.h"

struct LODSprite;
class DecorationDesc;
class GraphicsImage;

class Sprite {
 public:
    inline Sprite() {
        texture = nullptr;
        uAreaX = 0;
        uAreaY = 0;
        uWidth = 0;
        uHeight = 0;
        sprite_header = nullptr;
    }

    void Release();

    std::string pName;
    GraphicsImage *texture;
    int uAreaX; // TODO(captainurist): always zero,
    int uAreaY; // TODO(captainurist): was intended to support sprite maps?
    int uWidth; // Same as texture->width().
    int uHeight;

    LODSprite *sprite_header;
};

class SpriteFrame {
 public:
    std::string icon_name;
    std::string texture_name;

    /**
     * @return                              Returns int to Index of palette stored in palette manager.
     */
    int GetPaletteIndex();
    /**
     * @param index                         Index to set or default 0.
     */
    void ResetPaletteIndex(int index = 0);

    std::array<Sprite *, 8> hw_sprites = {{}};
    float scale = 1.0;
    int uFlags = 0;  // 128 for loaded - 1 for anim
    int uGlowRadius = 0;
    int uPaletteID = 0;
    int uAnimTime = 0;
    int uAnimLength = 0;
 private:
    int uPaletteIndex = 0;
};

struct SpriteFrameTable {
    void FromFile(const Blob &data_mm6, const Blob &data_mm7, const Blob &data_mm8);
    void ResetLoadedFlags();
    void InitializeSprite(signed int uSpriteID);
    int FastFindSprite(std::string_view pSpriteName);
    int BinarySearch(std::string_view pSpriteName);
    SpriteFrame *GetFrame(unsigned int uSpriteID, unsigned int uTime);
    SpriteFrame *GetFrameBy_x(unsigned int uSpriteID, signed int time);

    /**
     * Resets the uPaletteIndex of all loaded pSpriteSFrames. Called by PaletteManager on reset.
     */
    void ResetPaletteIndexes();

    std::vector<SpriteFrame> pSpriteSFrames;
    std::vector<SpriteFrame *> pSpritePFrames;
    std::vector<uint16_t> pSpriteEFrames;
};

extern struct SpriteFrameTable *pSpriteFrameTable;

SpriteFrame *LevelDecorationChangeSeason(const DecorationDesc *desc, int t, int month);
