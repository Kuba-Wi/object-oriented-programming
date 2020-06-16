#include <iostream>
#include <string>

class Ship {
private:
    int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;

public:
    Ship() : id_(-1) {}
    Ship(size_t id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity) :
        id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity) {}
    Ship(size_t id, size_t speed, size_t maxCrew) :
         Ship(id, "", speed, maxCrew, 0) {}

    void set_id(int id) { id_ = id; }
    int get_id() const { return id_; }

    void set_name(const std::string& name) { name_ = name; }
    std::string get_name() const { return name_; }

    void set_speed(size_t speed) { speed_ = speed; }
    int get_speed() const { return speed_; }

    void set_maxCrew(size_t maxCrew) { maxCrew_ = maxCrew; }
    size_t get_maxCrew() const { return maxCrew_; }

    void set_capacity(size_t capacity) { capacity_ = capacity; }
    size_t get_capacity() const { return capacity_; }

    Ship& operator+=(int crew) {
        crew_ += crew;
        if(crew_ > maxCrew_) {
            crew_ = maxCrew_;
        } 
        return *this; 
    }
    Ship& operator-=(int crew) { 
        if(crew_ < crew) {
            crew_ = 0;
        } else {
            crew_ -= crew;
        } 
        return *this;
    }

};

class Cargo {
private:
    std::string name_;
    size_t amount_;
    size_t basePrice_;

public:
    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(size_t amount) { 
        if(amount_ < amount) {
            amount_ = 0;
        } else {
            amount_ -= amount;
        }
        return *this;
    }

};
