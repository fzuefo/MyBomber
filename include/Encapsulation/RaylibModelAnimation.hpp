/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibModelAnimation
*/

#ifndef RAYLIBMODELANIMATION_HPP_
#define RAYLIBMODELANIMATION_HPP_

#include "IndieStudio.hpp"
#include "RaylibModelAnimationError.hpp"
#include <memory>
#include <chrono>

namespace Raylib
{
    enum AnimTypeEnum
    {
        WALK,
        WIN,
        DEATH,
        FLOSS
    };

    class RaylibModelAnimation {
        public:
            RaylibModelAnimation(
                const std::string &fileName,
                const AnimTypeEnum &type,
                const float frameDelay,
                const bool repeat = true
            );
            ~RaylibModelAnimation();
            void setModelAnimation(const std::string &fileName);
            void setModel(const Model &model);
            void setType(const AnimTypeEnum &type);
            void setFrameDelay(const float frameDelay);
            void setRepeat(const bool repeat);
            Model getModel() const;
            AnimTypeEnum getType() const;
            float getFrameDelay() const;
            bool getRepeat() const;
            void animate();
            bool isModelAnimationValid(Model model);

        private:
            unsigned int _animCount;
            std::unique_ptr<ModelAnimation> _animation;
            int _frame;
            Model _model;
            AnimTypeEnum _type;
            std::chrono::time_point<std::chrono::high_resolution_clock> _clock;
            float _frameDelay;
            bool _repeat;
    };
}

#endif /* !RAYLIBMODELANIMATION_HPP_ */
