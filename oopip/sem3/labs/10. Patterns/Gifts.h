#pragma once

#include "ConceptualRooms.h"

namespace gift {
    class Gift {
    public:
        virtual ~Gift() {}
        virtual void celebrate() const = 0;
    };

    class Discount : public Gift {
    public:
        void celebrate() const override {
            cout << "������� ��������� �����!" << endl;
        }
    };

    class BrandedNotebook : public Gift {
    public:
        void celebrate() const override {
            cout << "�������� �������������� �������!" << endl;
        }
    };

    class BrandedHeadphones : public Gift {
    public:
        void celebrate() const override {
            cout << "�������� �������������� ��������!" << endl;
        }
    };

    class Event {
    public:
        virtual ~Event() {}
        virtual Event* createEvent() const = 0;
        virtual Gift* distributeGift() const = 0;
        virtual void describe() const = 0;
    };

    class StandUP : public Event {
    public:
        Event* createEvent() const override { return new StandUP; }
        Discount* distributeGift() const override { return new Discount; }
        void describe() const {
            cout << "� ����� � ����������� �������� ��� ������� ��������� �����!" << endl;
        }
    };

    class Lecture : public Event {
    public:
        Event* createEvent() const override { return new Lecture; }
        BrandedNotebook* distributeGift() const override { return new BrandedNotebook; }
        void describe() const {
            cout << "� ����� � ����������� ������ ��� ������� �������������� �������!" << endl;
        }
    };

    class Meeting : public Event {
    public:
        Event* createEvent() const override { return new Meeting; }
        BrandedHeadphones* distributeGift() const override { return new BrandedHeadphones; }
        void describe() const {
            cout << "� ����� � ����������� ������� ���� �������� �������������� ��������!" << endl;
        }
    };

    class LiveBroadcast : public Event {
    public:
        Event* createEvent() const override { return new LiveBroadcast; }
        BrandedNotebook* distributeGift() const override { return new BrandedNotebook; }
        void describe() const {
            cout << "� ����� � ����������� ������ ���������� ��� ������� �������������� �������!" << endl;
        }
    };

    class TheatricalProduction : public Event {
    public:
        Event* createEvent() const override { return new TheatricalProduction; }
        Discount* distributeGift() const override { return new Discount; }
        void describe() const {
            cout << "� ����� � ����������� ����������� ���������� ��� ������� ��������� �����!" << endl;
        }
    };
}