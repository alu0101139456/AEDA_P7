#pragma once

class Contador_t
{
private:
    size_t count=0;
    size_t max=0;
    size_t min=-1;
    size_t acc=0;

public:

    Contador_t() = default;

    ~Contador_t() = default;

    void endCount (void){
        if (count > max)
            max = count;
        if (count < min)
            min = count;
        acc += count;
        count = 0;  
    };

    void reset(){ *this = Contador_t(); }

    Contador_t& operator++(){
        count++;
        return *this;
    }

    Contador_t operator++(int){
        Contador_t temp(*this);
        count++;
        return temp;
    }

    auto getResults() const -> decltype(std::make_tuple(count, max, min, acc))
    {
        return std::make_tuple(count, max, min, acc);
    }

    size_t getTotalCounts() const{
        return acc;
    }

    friend std::ostream& operator<<(std::ostream& os, const Contador_t& rhs)
    {
        os << rhs.getTotalCounts();
        return os;
    }

};

// };
