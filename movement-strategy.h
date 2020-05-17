
class MovementStrategy {
    public:
        virtual double x() = 0;
        virtual double y() = 0;
        virtual void set_x(double x) = 0;
        virtual void set_y(double y) = 0;

        virtual double dx() = 0;
        virtual double dy() = 0;
        virtual void set_dx(double dx) = 0;
        virtual void set_dy(double dy) = 0;
};

class RegularMovementStrategy : public MovementStrategy {
    public:
        ~RegularMovementStrategy(); //destructor, destroys the instance
        RegularMovementStrategy(int x,int y) : _x(x),_y(y){}; // constructor
        void set_x(double x);
        void set_y(double y);
        double x(){return _x;};
        double y(){return _y;};
        
        void set_dx(double dx);
        void set_dy(double dy);
        double dx(){return _dx;};
        double dy(){return _dy;};
    private:
        double _x = 0,_y = 0, _dx = 0, _dy = 0;
};

class LockDownMovementStrategy : public MovementStrategy{
    public:
        ~LockDownMovementStrategy();
        LockDownMovementStrategy(int x,int y) : _x(x),_y(y){};
        void set_x(double x);
        void set_y(double y);
        double x(){return _x;};
        double y(){return _y;};
        
        void set_dx(double dx);
        void set_dy(double dy);
        double dx(){return _dx;};
        double dy(){return _dy;};
    private:
        double _x = 0,_y = 0, _dx = 0, _dy = 0;
};

