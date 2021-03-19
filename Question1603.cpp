class ParkingSystem {

private:
    int slot_small;
    int slot_medium;
    int slot_big;

public:
    ParkingSystem(int big, int medium, int small) {
        slot_big = big;
        slot_medium = medium;
        slot_small = small;
    }
    
    bool addCar(int carType) {
        switch(carType){
            case 1:
                return (slot_big--)>0;
            case 2:
                return (slot_medium--)>0;
            case 3:
                return (slot_small--)>0;
        }
        return false;
    }
};
