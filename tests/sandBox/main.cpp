/*
65;6800;1c** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** main
*/


#include "IndieStudio.hpp"
#include "RaylibWindow.hpp"
#include "RaylibText.hpp"
#include "RaylibCamera.hpp"
#include "RaylibModel.hpp"
#include "RaylibTexture.hpp"
#include "RaylibModelAnimation.hpp"

#include "raymath.h"

int main(void)
{   
    // Init window text and camera
    Raylib::RaylibWindow window(1920, 1080, "Indie game");
    Raylib::RaylibText text("Si tu lis ce texte du dois une bierre ou un kebab a Baptiste", "./../assets/Minecraft.ttf");
    Raylib::RaylibCamera camera(45.0f, { 0.2f, 0.4f, 0.2f }, 0, { 0.0f, 0.0f, 0.0f }, {0.0f, 0.1f, 0.0f});

    /// Model texture load
    Raylib::RaylibTexture texture_steve("../assets/steve/steve.png");
    Raylib::RaylibTexture texture_enderman("../assets/enderman/enderman.png");
    Raylib::RaylibTexture texture_zombie("../assets/zombie/zombie.png");
    Raylib::RaylibTexture texture_villager("../assets/villager/villager.png");
    Raylib::RaylibTexture texture_grass("../assets/grass/grass.png");
    Raylib::RaylibTexture texture_stone("../assets/stone/stone.png");
    Raylib::RaylibTexture texture_tnt("../assets/tnt/tnt.png");
    Raylib::RaylibTexture texture_obsidian("../assets/obsidian/obsidian.png");
    Raylib::RaylibTexture texture_bedrock("../assets/bedrock/bedrock.png");
    Raylib::RaylibTexture texture_wood("../assets/wood/oak_planks.png");
    Raylib::RaylibTexture texture_chest("../assets/chest/chest.png");
    Raylib::RaylibTexture texture_arrow("../assets/arrow/aarow.png");
    
    /// Model 3d load
    // The Last argument concern the rotation for iqm Models
    Raylib::RaylibModel steve("../assets/steve/steve.iqm", (Vector3) { 10.0f, -1.0f, 4.0f }, (Vector3){ 0.0f, 1.0f, 0.0f }, -90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE, (Vector3){ 90.0f, 0.0f, 0.0f });
    Raylib::RaylibModel enderman("../assets/enderman/enderman.iqm", (Vector3) { 10.0f, -1.0f, 5.0f }, (Vector3){ 0.0f, 1.0f, 0.0f }, -90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE, (Vector3){ 90.0f, 0.0f, 0.0f });
    Raylib::RaylibModel zombie("../assets/zombie/zombie.iqm", (Vector3) { 10.0f, -1.0f, 6.0f }, (Vector3){ 0.0f, 1.0f, 0.0f }, -90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE, (Vector3){ 90.0f, 0.0f, 0.0f });
    Raylib::RaylibModel villager("../assets/villager/villager.iqm", (Vector3) { 10.0f, -1.0f, 7.0f }, (Vector3){ 0.0f, 1.0f, 0.0f }, -90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE, (Vector3){ 90.0f, 0.0f, 0.0f });
    Raylib::RaylibModel grass("../assets/grass/grass.obj", (Vector3) { 5.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
    Raylib::RaylibModel stone("../assets/stone/stone.obj", (Vector3) { 6.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
    Raylib::RaylibModel tnt("../assets/tnt/tnt.obj", (Vector3) { 7.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
    Raylib::RaylibModel obsidian("../assets/obsidian/obsidian.obj", (Vector3) { 8.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
    Raylib::RaylibModel bedrock("../assets/bedrock/bedrock.obj", (Vector3) { 9.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
    Raylib::RaylibModel wood("../assets/wood/wood.obj", (Vector3) { 10.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
    Raylib::RaylibModel chest("../assets/chest/chest.obj", (Vector3) { 11.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0, (Vector3){ 0.25f, 0.25f, 0.25f }, WHITE);
    Raylib::RaylibModel arrow("../assets/arrow/arrow.obj", (Vector3) { 12.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0, (Vector3){ 10.0f, 10.0f, 10.0f }, WHITE);
    Raylib::RaylibModel littleTnt("../assets/tnt/tnt.obj", (Vector3) { 13.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0, (Vector3){ 0.25f, 0.25f, 0.25f }, WHITE);


    // Model Animation loading
    Raylib::RaylibModelAnimation anim_steve("../assets/steve/steve.iqm", Raylib::FLOSS, 30.0f);
    Raylib::RaylibModelAnimation anim_ender("../assets/enderman/enderman.iqm", Raylib::WALK, 30.0f);
    Raylib::RaylibModelAnimation anim_zombie("../assets/zombie/zombie.iqm", Raylib::WALK, 30.0f);
    Raylib::RaylibModelAnimation anim_villager("../assets/villager/villager.iqm", Raylib::WALK, 30.0f);


    // Set a Model to an Animation
    anim_steve.setModel(steve.getModel());
    anim_ender.setModel(enderman.getModel());
    anim_zombie.setModel(zombie.getModel());
    anim_villager.setModel(villager.getModel());

    // Camera and text config
    text.setPos(Vector2{ 75, 200 });
    text.setFontSize(30);
    text.setColor((Color){ 255, 255, 255, 255 });
    camera.setCameraMode(CAMERA_FIRST_PERSON);
    camera.setCameraMoveControls(KEY_W, KEY_S, KEY_D, KEY_A, KEY_Q, KEY_E);

    // Set texture on Models
    steve.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_steve.getTexture());
    enderman.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_enderman.getTexture());
    zombie.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_zombie.getTexture());
    villager.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_villager.getTexture());
    grass.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_grass.getTexture());
    stone.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_stone.getTexture());
    tnt.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_tnt.getTexture());
    obsidian.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_obsidian.getTexture());
    bedrock.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_bedrock.getTexture());
    wood.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_wood.getTexture());
    chest.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_chest.getTexture());
    arrow.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_arrow.getTexture());
    littleTnt.setMaterialTexture(MATERIAL_MAP_DIFFUSE, texture_tnt.getTexture());

    while (!window.windowShouldClose()) {
        camera.updateCamera();
        window.beginDrawing();
        window.clearBackground();
        BeginMode3D(camera.getCamera());
            steve.draw();
            zombie.draw();
            enderman.draw();
            villager.draw();
            grass.draw();
            stone.draw();
            tnt.draw();
            obsidian.draw();
            bedrock.draw();
            wood.draw();
            chest.draw();
            arrow.draw();
            littleTnt.draw();
            DrawGrid(100, 1.0f);
        EndMode3D();
        text.draw();
        window.endDrawing();
        anim_steve.animate();
        anim_ender.animate();
        anim_zombie.animate();
        anim_villager.animate();

    }
    return 0;
}
