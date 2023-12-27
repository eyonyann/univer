#pragma once

#include "ConceptualRooms.h"

enum MerchandiseUnits { LOGO_MUG, MOVIE_POSTER, BRANDED_PILLOW, COLLECTIBLE_TOY, BRANDED_KEYRING, null0 };

class MerchandiseUnit {
public:
    virtual ~MerchandiseUnit() {}
    virtual void displayInfo() const = 0;
    virtual void describe() const = 0;
};

class LogoMug : public MerchandiseUnit {
private:
    int mugSize;
    bool isThermal;

public:
    void displayInfo() const override {
        cout << "Была создана чашка с логотипом!" << endl;
    }
    void describe() const override {
        cout << "Чашка с логотипом размера " << this->mugSize << "." << endl;
    }
    LogoMug(int size, bool thermal) : mugSize(size), isThermal(thermal) {}
};

class MoviePoster : public MerchandiseUnit {
private:
    string movieTitle;
    int posterSize;

public:
    void displayInfo() const override {
        cout << "Был создан постер!" << endl;
    }
    void describe() const override {
        cout << "Постер к фильму " << this->movieTitle << ", имеющий размер " << this->posterSize << endl;
    }
    MoviePoster(const string& title, int size) : movieTitle(title), posterSize(size) {}
};

class BrandedPillow : public MerchandiseUnit {
private:
    string pillowColor;
    bool hasLogo;

public:
    void displayInfo() const override {
        cout << "Была создана подушка с логотипом!" << endl;
    }
    void describe() const override {
        cout << "Подушка с логотипом, имеющая цвет " << this->pillowColor << endl;
    }
    BrandedPillow(const string& color, bool logo) : pillowColor(color), hasLogo(logo) {}
};

class CollectibleToy : public MerchandiseUnit {
private:
    string characterName;
    int toyHeight;

public:
    void displayInfo() const override {
        cout << "Была создана коллекционная игрушка!" << endl;
    }
    void describe() const override {
        cout << "Коллекционная игрушка персонажа " << this->characterName << ", имеющая размер " << this->toyHeight << endl;
    }
    CollectibleToy(const string& name, int height) : characterName(name), toyHeight(height) {}
};

class BrandedKeyring : public MerchandiseUnit {
private:
    string material;
    bool hasLight;

public:
    void displayInfo() const override {
        cout << "Был создан брендовый брелок!" << endl;
    }
    void describe() const override {
        cout << "Брелок с логотипом, сделанный из " << this->material << endl;
    }
    BrandedKeyring(const string& mat, bool light) : material(mat), hasLight(light) {}
};

class MerchandiseUnitSpec {
public:
    virtual MerchandiseUnits unitType() const = 0;
    virtual MerchandiseUnit* createUnit() const = 0;
};

class LogoMugSpec : public MerchandiseUnitSpec {
public:
    MerchandiseUnits unitType() const override { return LOGO_MUG; }
    int mugSize;
    bool isThermal;

    LogoMugSpec(int size, bool thermal) : mugSize(size), isThermal(thermal) {}

    MerchandiseUnit* createUnit() const override {
        return new LogoMug(mugSize, isThermal);
    }
};

class MoviePosterSpec : public MerchandiseUnitSpec {
public:
    MerchandiseUnits unitType() const override { return MOVIE_POSTER; }
    string movieTitle;
    int posterSize;

    MoviePosterSpec(const string& title, int size) : movieTitle(title), posterSize(size) {}

    MerchandiseUnit* createUnit() const override {
        return new MoviePoster(movieTitle, posterSize);
    }
};

class BrandedPillowSpec : public MerchandiseUnitSpec {
public:
    MerchandiseUnits unitType() const override { return BRANDED_PILLOW; }
    string pillowColor;
    bool hasLogo;

    BrandedPillowSpec(const string& color, bool logo) : pillowColor(color), hasLogo(logo) {}

    MerchandiseUnit* createUnit() const override {
        return new BrandedPillow(pillowColor, hasLogo);
    }
};

class CollectibleToySpec : public MerchandiseUnitSpec {
public:
    MerchandiseUnits unitType() const override { return COLLECTIBLE_TOY; }
    string characterName;
    int toyHeight;

    CollectibleToySpec(const string& name, int height) : characterName(name), toyHeight(height) {}

    MerchandiseUnit* createUnit() const override {
        return new CollectibleToy(characterName, toyHeight);
    }
};

class BrandedKeyringSpec : public MerchandiseUnitSpec {
public:
    MerchandiseUnits unitType() const override { return BRANDED_KEYRING; }
    string material;
    bool hasLight;

    BrandedKeyringSpec(const string& mat, bool light) : material(mat), hasLight(light) {}

    MerchandiseUnit* createUnit() const override {
        return new BrandedKeyring(material, hasLight);
    }
};

MerchandiseUnit* createMerchandiseUnitWithSpec(const MerchandiseUnitSpec* unitSpec) {
    return unitSpec->createUnit();
}
