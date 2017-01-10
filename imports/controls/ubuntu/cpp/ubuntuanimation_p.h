/*
 * Copyright 2013-2016 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UCUBUNTUANIMATION_P_H
#define UCUBUNTUANIMATION_P_H

#include <QtCore/QEasingCurve>
#include <QtCore/QObject>

#include <ubuntutoolkitglobal.h>

UT_NAMESPACE_BEGIN

class UBUNTUTOOLKIT_EXPORT UbuntuAnimation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int SnapDuration READ SnapDuration CONSTANT)
    Q_PROPERTY(int FastDuration READ FastDuration CONSTANT)
    Q_PROPERTY(int BriskDuration READ BriskDuration CONSTANT)
    Q_PROPERTY(int SlowDuration READ SlowDuration CONSTANT)
    Q_PROPERTY(int SleepyDuration READ SleepyDuration CONSTANT)
    Q_PROPERTY(QEasingCurve StandardEasing READ StandardEasing CONSTANT)
    Q_PROPERTY(QEasingCurve StandardEasingReverse READ StandardEasingReverse CONSTANT)

public:
    explicit UbuntuAnimation(QObject *parent = 0);
    
    int SnapDuration() const { return 100; }
    int FastDuration() const { return 165; }
    int BriskDuration() const { return 333; }
    int SlowDuration() const { return 500; }
    int SleepyDuration() const { return 1000; }
    const QEasingCurve& StandardEasing() const {
        return m_standardEasing;
    }
    const QEasingCurve& StandardEasingReverse() const {
        return m_StandardEasingReverse;
    }

private:
    QEasingCurve m_standardEasing;
    QEasingCurve m_StandardEasingReverse;
};

UT_NAMESPACE_END

#endif // UCUBUNTUANIMATION_P_H
