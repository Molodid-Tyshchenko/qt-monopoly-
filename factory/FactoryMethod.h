#include "../fields/Field.h"
#include "../fields/BasicField.h"
#include "../fields/GiftField.h"
#include "../fields/PolyanaField.h"
#include "../fields/PortalField.h"
#include "../fields/QuestionField.h"
#include "../fields/SelectiveField.h"
#include "../fields/StartField.h"
#include "../fields/VadimField.h"

class FieldFactory {
public:
    virtual std::shared_ptr<Field> createField() const = 0;
};

class BasicFieldFactory : public FieldFactory {
public:
    std::shared_ptr<Field> createField() const {
        return std::make_shared<BasicField>();
    }
};

class GiftFieldFactory : public FieldFactory{
public:
    std::shared_ptr<Field> createField() const {
        return std::make_shared<GiftField>();
    }
};

class PolyanaFieldFactory : public FieldFactory{
public:
    std::shared_ptr<Field> createField() const {
        return std::make_shared<PolyanaField>();
    }
};

class PortalFieldFactory : public FieldFactory{
public:
    std::shared_ptr<Field> createField() const {
        return std::make_shared<PortalField>();
    }
};

class QuestionFieldFactory : public FieldFactory{
public:
    std::shared_ptr<Field> createField() const {
        return std::make_shared<QuestionField>();
    }
};

class SelectiveFieldFactory : public FieldFactory{
public:
    std::shared_ptr<Field> createField() const {
        return std::make_shared<SelectiveField>();
    }
};

class StartFieldFactory : public FieldFactory {
public:
    std::shared_ptr<Field> createField() const {
        return std::make_shared<StartField>();
    }
};

class VadimFieldFactory : public FieldFactory{
public:
    std::shared_ptr<Field> createField() const {
        return std::make_shared<VadimField>();
    }
};
