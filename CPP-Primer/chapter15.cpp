class Quote{
public :
  Quote() = default;
  Quote(const std::string &book,double sales_price):
    bookNo(book),
    price(sales_price)
  {
  }

  virtual ~Quote() = default;


  std::string isbn() const;
  virtual double net_price(std::size_t n) const
  {
    return n*price;
  }

  virtual void show(std::size_t n) const {} = 0;

private:
  std::string bookNo;
protected:
  doube price = 0.0;
}

  class Bulk_quote final: public Quote{
  public:
    double net_price(std::size_t ) const override;
  }
