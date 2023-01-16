#pragma once

struct QueueOnRing
{
	int value;
	QueueOnRing* Next = nullptr;
};

struct QueueOnRingList
{
	QueueOnRing* Head = nullptr;
	QueueOnRing* Oldest = nullptr;
	QueueOnRing* Newest = nullptr;
};