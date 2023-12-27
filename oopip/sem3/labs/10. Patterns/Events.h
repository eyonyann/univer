#pragma once

#include "ConceptualRooms.h"

class Event;
typedef Event* (*EventFactory) ();
int eventTypeCounter = 0;
vector<pair<int, EventFactory>> eventRegistry;
void RegisterEvent(EventFactory factory) {
	eventRegistry.push_back(make_pair(eventTypeCounter++, factory));
}

class Event {
public:
	static Event* createEvent(int eventType) {
		EventFactory factory = eventRegistry[eventType].second;
		return factory();
	}
	virtual void describe() const = 0;
};

class StandUP : public Event {
public:
	static Event* createEvent() { return new StandUP; }
	static void Register() {
		RegisterEvent(StandUP::createEvent);
	}
	void describe() const {
		cout << "Мероприятие стендап." << endl;
	}
};

class Lecture : public Event {
public:
	static Event* createEvent() { return new Lecture; }
	static void Register() {
		RegisterEvent(Lecture::createEvent);
	}
	void describe() const {
		cout << "Лекция приглашенного спикера." << endl;
	}
};

class Meeting : public Event {
public:
	static Event* createEvent() { return new Meeting; }
	static void Register() {
		RegisterEvent(Meeting::createEvent);
	}
	void describe() const {
		cout << "Встреча с приглашенной знаменитостью." << endl;
	}
};

class LiveBroadcast : public Event {
public:
	static Event* createEvent() { return new LiveBroadcast; }
	static void Register() {
		RegisterEvent(LiveBroadcast::createEvent);
	}
	void describe() const {
		cout << "Просмотр прямого эфира оговоренного мероприятия." << endl;
	}
};

class TheatricalProduction : public Event {
public:
	static Event* createEvent() { return new TheatricalProduction; }
	static void Register() {
		RegisterEvent(TheatricalProduction::createEvent);
	}
	void describe() const {
		cout << "Театральная постановка по делаемой теме." << endl;
	}
};