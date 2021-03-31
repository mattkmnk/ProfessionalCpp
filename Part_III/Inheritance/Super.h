#pragma once

class Super {
public:
    Super();
    virtual void someMethod();

protected:
    int mProtectedInt;

private:
    int mPrivateInt;
};

class Sub : public Super {
public:
    Sub();
    virtual void someMethod() override;
    virtual void someOtherMethod();
};