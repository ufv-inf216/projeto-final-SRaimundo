//
// Created by julio on 10/11/23.
//

#ifndef SUPER_CAPI_FIGHTERS_PLAYER_H
#define SUPER_CAPI_FIGHTERS_PLAYER_H

#pragma once
#include "Actor.h"
#include "Utils/Character.h"


enum class FightStatus {
    Fight,
    Win,
    Lose
};

class Player: public Actor {
public:
    explicit Player(Scene* scene, Vector2 position, int playerNumber, CharacterSelect characterSelect, float heart = 100.0f, float forwardSpeed = 1000.0f, float jumpSpeed = -1000.0f);

    void OnProcessInput(const Uint8* keyState) override;
    void OnUpdate(float deltaTime) override;
    void OnCollision(std::unordered_map<CollisionSide, AABBColliderComponent::Overlap>& responses) override;
    void ApplyDamage(float damage) override;

    void Kill() override;
    void EndFight();
    void StopAnimationTimer(float deltaTime, float animationTime, std::string variable);



private:
    void ManageAnimations();

    class RigidBodyComponent* mRigidBodyComponent;
    class DrawAnimatedComponent* mDrawComponent;
    class AABBColliderComponent* mMovementColliderComponent;
    class AABBColliderComponent* mAttackColliderComponent;
    class AABBColliderComponent* mPunchColliderComponent;
    class DrawPolygonComponent* mDrawPolygonComponent;
    class DrawPolygonComponent* mDrawPunchComponent;
    class DrawHealthBar* mDrawHealthBar;


    float mForwardSpeed;
    float mJumpSpeed;

    bool mIsMoving;
    bool mIsDead;
    bool mIsOnGround;
    bool mIsJumping;
    bool mIsBlocking;
    bool mIsPunching;
    bool mIsKicking;
    bool mIsDown;
    bool mIsDamage;

    float mAnimationTimer;


    FightStatus mFightStatus;

    int mPlayerNumber;
    Character* mCharacter;
    CharacterSelect mCharacterSelect;
//    float mHeart;
//    float mMaxHeart;
};


#endif //SUPER_CAPI_FIGHTERS_PLAYER_H
