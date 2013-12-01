/*
* Ozone - iOS Edition
* Copyright (C) 2009-2013 Ignacio Sanchez

* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program. If not, see http://www.gnu.org/licenses/
*
*/

/* 
 * File:   spittingenemy.h
 * Author: nacho
 *
 * Created on 22 de marzo de 2009, 23:53
 */

#pragma once
#ifndef _SPITTINGENEMY_H
#define	_SPITTINGENEMY_H

#include "enemy.h"

#define SPITTING_ENEMY_CADENCY (0.2f)

class SpittingEnemy : public Enemy
{

private:

    float m_fLastTimeThrown;
    float m_fFinalRotation;

    Vec3 m_vStartThrowingPosition;
    Vec3 m_vThrowingDir;

public:
    SpittingEnemy(void);
    virtual void Init(short posX, short posY, u8 rotation, short width, short height, char* szScript);
    virtual void Update(Timer* timer);

    virtual void Enable(void);
    virtual void Disable(void);
    virtual void Reset(void);

    virtual void ContactWithPlayer(Player* thePlayer, const float impulse, Timer* timer);

    virtual void getWorldTransform(btTransform &worldTransform) const;
    virtual void ContactWithPlayerNuke(Player* thePlayer, const float impulse, Timer* timer, int additionalData);

    virtual void Kill(void);

    virtual bool AffectedByElectricity(void)
    {
        return true;
    };

    virtual const Vec3& GetRealPosition(void) const
    {
        return m_vStartThrowingPosition;
    };
};

#endif	/* _SPITTINGENEMY_H */

