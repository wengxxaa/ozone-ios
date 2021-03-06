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
 *  Timer.h
 *  PuzzleStar
 *
 *  Created by nacho on 19/11/08.
 *  Copyright 2008 d. All rights reserved.
 *
 */

#pragma once
#ifndef _TIMER_H
#define	_TIMER_H

#include <mach/mach.h>
#include <mach/mach_time.h>
#include "defines.h"

#define FPS_REFRESH_TIME	0.5f

#ifdef DEBUG_OZONE
#define FRAME_RATE_AVERAGE 1
#else
#define FRAME_RATE_AVERAGE 5
#endif

class Timer
{

public:

    Timer(void);

    Timer(bool calculateFPS)
    {
        Log("+++ Timer::Timer contador FPS...\n");

        m_bCalculateFPS = calculateFPS;

        Reset();

        Log("+++ Timer::Timer correcto\n");
    };

    ~Timer(void);
    void Start(void);
    void Stop(void);
    void Continue(void);

    float GetActualTime(void) const;
    float GetFrameTime(void) const;
    float GetDeltaTime(void) const;

    void Reset(void);
    void Update(void);
    float GetFPS(void) const;

    bool IsRunning(void) const;

    void SetOffset(const float offset)
    {
        m_fOffset = offset;
    };

private:

    bool m_bCalculateFPS;
    bool m_bIsRunning;

    float m_fOffset;

    u64 m_i64BaseTicks;
    u64 m_i64StopedTicks;

    float m_fResolution;

    float m_fFrameTime;
    float m_fDeltaTime;

    u32 m_iFrameCount;
    float m_fLastUpdate;
    float m_fFPS;

    float m_fDeltaTimeAccumulation[FRAME_RATE_AVERAGE];
    int m_iCurrentAccumulator;
};

#endif	/* _TIMER_H */
