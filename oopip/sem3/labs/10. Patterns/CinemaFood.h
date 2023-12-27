#pragma once

#include "ConceptualRooms.h"

class Food {
public:
    virtual ~Food() {}
    virtual Food* clone() const = 0;
    virtual void sell() const = 0;
};

class Popcorn : public Food {
public:
    Popcorn* clone() const override {
        return new Popcorn(*this);
    }

    void sell() const override {
        cout << "Попкорн распродан." << endl;
    }
};

class Soda : public Food {
public:
    Soda* clone() const override {
        return new Soda(*this);
    }

    void sell() const override {
        cout << "Напитки распроданы." << endl;
    }
};

class HotDog : public Food {
public:
    HotDog* clone() const override {
        return new HotDog(*this);
    }

    void sell() const override {
        cout << "Хотдог распродан." << endl;
    }
};

class IceCream : public Food {
public:
    IceCream* clone() const override {
        return new IceCream(*this);
    }

    void sell() const override {
        cout << "Мороженое распродано." << endl;
    }
};