/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GridPosition_h
#define GridPosition_h

namespace WebCore {

enum GridPositionType {
    AutoPosition,
    IntegerPosition,
    SpanPosition
};

class GridPosition {
public:
    GridPosition()
        : m_type(AutoPosition)
        , m_integerPosition(0)
    {
    }

    bool isPositive() const { return integerPosition() > 0; }

    GridPositionType type() const { return m_type; }
    bool isAuto() const { return m_type == AutoPosition; }
    bool isInteger() const { return m_type == IntegerPosition; }
    bool isSpan() const { return m_type == SpanPosition; }

    void setIntegerPosition(int position)
    {
        m_type = IntegerPosition;
        m_integerPosition = position;
    }

    // 'span' values cannot be negative, yet we reuse the <integer> position which can
    // be. This means that we have to convert the span position to an integer, losing
    // some precision here. It shouldn't be an issue in practice though.
    void setSpanPosition(int position)
    {
        m_type = SpanPosition;
        m_integerPosition = position;
    }

    int integerPosition() const
    {
        ASSERT(type() == IntegerPosition);
        return m_integerPosition;
    }

    int spanPosition() const
    {
        ASSERT(type() == SpanPosition);
        return m_integerPosition;
    }

    bool operator==(const GridPosition& other) const
    {
        return m_type == other.m_type && m_integerPosition == other.m_integerPosition;
    }

    bool shouldBeResolvedAgainstOppositePosition() const
    {
        return isAuto() || isSpan();
    }
private:
    GridPositionType m_type;
    int m_integerPosition;
};

} // namespace WebCore

#endif // GridPosition_h
