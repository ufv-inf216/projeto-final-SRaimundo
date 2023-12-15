// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Actor.h"
#include "../Game.h"
#include "../Components/Component.h"
#include <algorithm>

Actor::Actor(Scene* scene, Vector2 position)
        : mState(ActorState::Active)
        , mPosition(position)
        , mScale(1.0f)
        , mRotation(0.0f)
        , mScene(scene)
{
    mScene->GetGame()->AddActor(this);
}

Actor::~Actor()
{
    mScene->GetGame()->RemoveActor(this);

    for(auto component : mComponents)
    {
        delete component;
    }
    mComponents.clear();
}

void Actor::Update(float deltaTime)
{
    if (mState == ActorState::Active)
    {
        for (auto comp : mComponents)
        {
            if(comp->IsEnabled())
            {
                comp->Update(deltaTime);
            }
        }

        OnUpdate(deltaTime);
    }
}

void Actor::OnUpdate(float deltaTime)
{

}

void Actor::OnCollision(std::unordered_map<CollisionSide, AABBColliderComponent::Overlap>& responses)
{

}

void Actor::Kill()
{

}

void Actor::ProcessInput(const Uint8* keyState)
{
    if (mState == ActorState::Active)
    {
        for (auto comp : mComponents)
        {
            comp->ProcessInput(keyState);
        }

        OnProcessInput(keyState);
    }
}

void Actor::OnProcessInput(const Uint8* keyState)
{

}

void Actor::AddComponent(Component* c)
{
    mComponents.emplace_back(c);
    std::sort(mComponents.begin(), mComponents.end(), [](Component* a, Component* b) {
        return a->GetUpdateOrder() < b->GetUpdateOrder();
    });
}

void Actor::ApplyDamage(float damage) {

}

