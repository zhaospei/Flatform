#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) {
    this->body = &body;
}
Collider::Collider(sf::RectangleShape* body) {
    this->body = body;
}
int Collider::checkCollision(Collider* other,float push) {
    sf::Vector2f otherPosition = other->getPosition();
    sf::Vector2f otherHaftSize = other->getHaftSize();
    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHaftSize = getHaftSize();
    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - (otherHaftSize.x + thisHaftSize.x);
    float intersectY = abs(deltaY) - (otherHaftSize.y + thisHaftSize.y);
    if (intersectX < 0.0f && intersectY < 0.0f) {
        push = std::min(std::max(push, 0.0f), 1.0f);
        if (intersectX > intersectY) {
            if (deltaX > 0.0f) { 
                if (push == 1.0f) {
                    other->body->setPosition(thisPosition.x + thisHaftSize.x + otherHaftSize.x, other->body->getPosition().y);
                    return collider::_right;
                }
                Move(intersectX * (1.0f - push), 0.0f);
                other->Move(-intersectX * push, 0.0f);
                return collider::right;
            }
            else {
                if (push == 1.0f) {
                    other->body->setPosition(thisPosition.x - thisHaftSize.x - otherHaftSize.x, other->body->getPosition().y);
                    return collider::_left;
                }
                Move(-intersectX * (1.0f - push), 0.0f);
                other->Move(intersectX * push, 0.0f);   
                return collider::left;
            }
        }
        else {
            if (deltaY > 0.0f) {
                if (push == 1.0f) {
                    other->body->setPosition(other->body->getPosition().x, thisPosition.y + thisHaftSize.y + otherHaftSize.y);
                    return collider:: _down;
                }
                Move(0.0f, intersectY * (1.0f - push));
                other->Move(0.0f, -intersectY * push);
                return collider::down;
            }
            else {
                if (push == 1.0f) {
                    other->body->setPosition(other->body->getPosition().x, thisPosition.y - thisHaftSize.y - otherHaftSize.y);
                    return collider::_top;
                }
                else {
                    Move(0.0f, -intersectY * (1.0f - push));
                    other->Move(0.0f, intersectY * push);
                    return collider::top;
                }
            }
        }
    }
    if (intersectX < 0.0f && intersectY <= 0.0f) {
        if (intersectX == 0.0f) {
            if (thisPosition.x < otherPosition.x) {
                return collider::_right;
            }
            else {
                return collider::_left;
            }
        }
        if (intersectY == 0.0f) {
            if (otherPosition.y < thisPosition.y)
                return collider::_top;
        }
    }
    return 0;
}
int Collider::checkCollision(Collider *other) {
    sf::Vector2f otherPosition = other->getPosition();
    sf::Vector2f otherHaftSize = other->getHaftSize();
    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHaftSize = getHaftSize();
    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - (otherHaftSize.x + thisHaftSize.x);
    float intersectY = abs(deltaY) - (otherHaftSize.y + thisHaftSize.y);
    if (intersectX < 0.0f && intersectY < 0.0f) {
        if (intersectX > intersectY) {
            if (deltaX > 0.0f) {
                return collider::right;
            }
            else {
                return collider::left;
            }
        }
        else {
            if (deltaY > 0) {
                return collider::down;
            }
            else {
                return collider::top;
            }
        }
    }
    if (intersectX <= 0.0f && intersectY <= 0.0f) {
        if (intersectX > intersectY) {
            if (deltaX > 0.0f) {
                return collider::_right;
            }
            else {
                return collider::_left;
            }
        }
        else {
            if (deltaY > 0) {
                return collider::_down;
            }
            else {
                return collider::_top;
            }
        }
    }
    return 0;
}
sf::Vector2f Collider::getPosition() {
    return body->getPosition();
}
sf::Vector2f Collider::getHaftSize() {
    return body->getSize() / 2.0f;
}
void Collider::Move(const float& x,const float& y) {
    body->move(sf::Vector2f(x, y));
}
