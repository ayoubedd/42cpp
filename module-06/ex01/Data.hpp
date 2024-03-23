#ifndef __DATA_HPP__

class Data {
  public:
    Data(void);
    Data(const Data& src);
    ~Data(void);

    Data& operator=(const Data& src);
  
    void greeting(void) const;
};

#endif // !__DATA_HPP__
