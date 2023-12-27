#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

enum ConceptualRooms { VR_ROOM, KIDS_ROOM, VIP_ROOM, BEDS_ROOM, COUCHES_ROOM, null, EMPTY_ROOM };

class ConceptualRoom {
public:
	virtual void describe() const = 0;
	virtual void bookTicket() const = 0;
	virtual ~ConceptualRoom() {}
};

class VRRoom : public ConceptualRoom {
public:
	void describe() const override {
		cout << "Комната с технологией виртуальной реальности." << endl;
	}
	void bookTicket() const override {
		cout << "Билет на VR-комнату забронирован." << endl;
	}
};

class KidsRoom : public ConceptualRoom {
public:
	void describe() const override {
		cout << "Комната для детей с интерактивными элементами." << endl;
	}
	void bookTicket() const override {
		cout << "Билет на детскую комнату забронирован." << endl;
	}
};

class VIPRoom : public ConceptualRoom {
public:
	void describe() const override {
		cout << "VIP-комната повышенного комфорта." << endl;
	}
	void bookTicket() const override {
		cout << "Билет на VIP-комнату забронирован." << endl;
	}
};

class BedsRoom : public ConceptualRoom {
public:
	void describe() const override {
		cout << "Комната с комфортными кроватями вместо привычных кресел." << endl;
	}
	void bookTicket() const override {
		cout << "Билет на комнату с кроватями забронирован." << endl;
	}
};

class CouchesRoom : public ConceptualRoom {
public:
	void describe() const override {
		cout << "Комната с комфортными диванами вместо привычных кресел." << endl;
	}
	void bookTicket() const override {
		cout << "Билет на комнату с диванами забронирован." << endl;
	}
};

class EmptyRoom : public ConceptualRoom {
public:
	void describe() const override {
		cout << " Пустая комната для собственных нужд." << endl;
	}
	void bookTicket() const override {
		cout << "Билет на пустую комнату забронирован." << endl;
	}
};

ConceptualRoom* createRoom(ConceptualRooms roomType) {
	switch (roomType) {
	case VR_ROOM:
		return new VRRoom();
	case KIDS_ROOM:
		return new KidsRoom();
	case VIP_ROOM:
		return new VIPRoom();
	case BEDS_ROOM:
		return new BedsRoom();
	case COUCHES_ROOM:
		return new CouchesRoom();
	case EMPTY_ROOM:
		return new EmptyRoom();
	default:
		return nullptr;
	}
}