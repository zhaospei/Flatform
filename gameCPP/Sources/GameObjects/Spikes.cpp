#include "Spikes.h"

Spikes::Spikes(const sf::Vector2f& position,bool direction)
{
    this->direction = direction;
    animtion = new Animation("Spikes/spikes" + to_string(direction), sf::Vector2u(2, 1), 0.0f);
    setSize(sf::Vector2f(_SIZE_, _SIZE_));
    setOrigin(getSize() / 2.0f);
    setPosition(position);
    setTexture(animtion->getTexture());
    collider = new Collider(*this);
}

Spikes::~Spikes()
{
    if (animtion != nullptr) {
        delete animtion;
    }
    if (collider != nullptr) {
        delete collider;
    }
}

bool Spikes::checkPlayer(Player* player)
{
    if (direction == 1) return checkTop(player);
    else return checkDown(player);
}

bool Spikes::checkTop(Player* player)
{
    int Check = collider->checkCollision(player->getCollider());
    if (Check == collider::top || Check == collider::_top) {
        return true;
    }
    return false;
}

bool Spikes::checkDown(Player* player)
{
    if (player->end) {
        return false;
    }
    if (touch_Gound) { 
        int Check = collider->checkCollision(player->getCollider(), 1.0f);
        if (Check == collider::top || Check == collider::_top) {
            player->canJump = true;
        }
        return false;
    }
    if (can_Drop == false && abs(getPosition().x - player->getPosition().x) <= 10.0f && (0.0f <= player->getPosition().y - getPosition().y && player->getPosition().y - getPosition().y <= 200.0f)) {
        can_Drop = true;
        animtion->currentFrame.x = 1;
    }
     int Check = collider->checkCollision(player->getCollider());
     if (Check == collider::down || Check == collider::_down) {
         return true;
     }
     return false;
}

void Spikes::Update(const float& deltaTime)
{
    if ( direction == 0 && can_Drop && touch_Gound == false ) {
        velocity.y += 10.0f * deltaTime;
        move(velocity);
    }
    animtion->update();
    setTextureRect(*animtion);
}

void Spikes::Render(sf::RenderWindow* window)
{
    window->draw(*this);
}

Collider* Spikes::getCollider()
{
    return collider;
}
