/*
 * Copyright 2016 Canonical Ltd.
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

#include "ubuntunumberanimation_p.h"
#include "ubuntuanimation_p.h"

UT_NAMESPACE_BEGIN

UbuntuNumberAnimation::UbuntuNumberAnimation(QObject *parent)
    : QQuickNumberAnimation(parent)
{
    UbuntuAnimation animation;
    setDuration(animation.FastDuration());
    setEasing(animation.StandardEasing());
}

UT_NAMESPACE_END
