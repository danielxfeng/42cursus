# pragma once
# include <string>

class Brain {
    public:
        Brain(void);
        Brain(const Brain &o);
        Brain &operator=(const Brain &o);
        ~Brain(void);

    private:
        std::string ideas_[100];
};
