/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibModelAnimation
*/

#include "RaylibModelAnimation.hpp"

namespace Raylib
{
    RaylibModelAnimation::RaylibModelAnimation(
        const std::string &fileName,
        const AnimTypeEnum &type,
        const float frameDelay,
        const bool repeat
    )
    {   
        _animCount = 1;
        _animation.reset(LoadModelAnimations(fileName.c_str(), &_animCount));
        _frame = 0;
        _model = {0};
        _type = type;
        _clock = std::chrono::high_resolution_clock::now();
        _frameDelay = frameDelay;
        _repeat = repeat;
    }

    void RaylibModelAnimation::setModelAnimation(const std::string &fileName)
    {
        if (_animation != nullptr)
            UnloadModelAnimation(*_animation);
        _animation.reset(LoadModelAnimations(fileName.c_str(), &_animCount));
    }

    void RaylibModelAnimation::setModel(const Model &model)
    {
        if (_animation == nullptr)
            throw Error::RaylibModelAnimationError("Model anim not exists");
        _model = model;
    }

    void RaylibModelAnimation::setType(const AnimTypeEnum &type)
    {
        _type = type;
    }

    void RaylibModelAnimation::setFrameDelay(const float frameDelay)
    {
        _frameDelay = frameDelay;   
    }

    void RaylibModelAnimation::setRepeat(const bool repeat)
    {
        _repeat = repeat;
    }
    
    Model RaylibModelAnimation::getModel() const
    {
        return _model;
    }

    AnimTypeEnum RaylibModelAnimation::getType() const
    {
        return _type;   
    }

    float RaylibModelAnimation::getFrameDelay() const
    {
        return _frameDelay;
    }

    bool RaylibModelAnimation::getRepeat() const
    {
        return _repeat;
    }

    void RaylibModelAnimation::animate()
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> newTime;
        std::chrono::duration<float> duration;

        if (_animation == nullptr)
            throw Error::RaylibModelAnimationError("Model anim not exists");
        if (_type > _animCount)
            throw Error::RaylibModelAnimationError("Animation type not loaded");
        newTime = std::chrono::high_resolution_clock::now();
        duration = (newTime - _clock) * 1000;
        if (duration.count() >= _frameDelay) {
            _clock = newTime;
            if (_frame < _animation.get()[_type].frameCount - 1)
                _frame++;
            if (_frame >= (_animation.get()[_type].frameCount - 1) && _repeat)
                _frame = 0;
            UpdateModelAnimation(_model, _animation.get()[_type], _frame);
        }
    }

    bool RaylibModelAnimation::isModelAnimationValid(Model model)
    {
        if (_animation == nullptr)
            throw Error::RaylibModelAnimationError("Model anim not exists");

        return IsModelAnimationValid(model, *_animation);
    }

    RaylibModelAnimation::~RaylibModelAnimation()
    {
        if (_animation != nullptr)
            UnloadModelAnimation(*_animation);
    }
}
