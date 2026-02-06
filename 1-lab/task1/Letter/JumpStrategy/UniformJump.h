#pragma once
#include "IJumpStrategy.h"


class UniformJump : public IJumpStrategy
{
private:
    float velocityY; // Скорость
    const float gravity;
    const float jumpForce;
    float groundLevel;

public:
    explicit UniformJump(
        float jumpForce,
        float gravity = 980.0f
    ): velocityY(0),
       gravity(gravity),
       jumpForce(jumpForce),
       groundLevel(0) {}

    void StartJumping(Letter &letter) override
    {
        velocityY = -jumpForce;
        groundLevel = letter.GetPositionY();
    }

    void Update(float deltaTime, Letter &letter) override
    {
        float &positionY = letter.GetPositionY();

        velocityY += gravity * deltaTime; // v = v0 + a*t
        positionY += velocityY * deltaTime; // S = S0 + v*t

        if (positionY >= groundLevel)
        {
            positionY = groundLevel;

            velocityY = -velocityY;
        }
    }
};
