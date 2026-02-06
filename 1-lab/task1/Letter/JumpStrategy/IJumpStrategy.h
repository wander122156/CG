#pragma once
class Letter;

class IJumpStrategy
{
public:
    virtual ~IJumpStrategy() = default;

    virtual void StartJumping(Letter& letter) = 0;
    virtual void Update(float deltaTime, Letter& letter) = 0;
};
