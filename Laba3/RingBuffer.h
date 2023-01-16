#pragma once

struct RingBuffer
{
    int value;
    RingBuffer* Next = nullptr;
};

struct RingBufferList
{
    RingBuffer* Head = nullptr;
    RingBuffer* Oldest = nullptr;
    RingBuffer* Newest = nullptr;
};