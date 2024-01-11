namespace ann{
class Neural
{
public: 
	virtual double function(const double& x) const=0;
	virtual double derivate(const double& x) const=0;
	virtual void learning(const double& x, const double& y,const double& y1)=0;
};
class parameter : public Neural
{
public:
	parameter(){};
	double function(const double& x) const override;
	double derivate(const double& x) const  override;
	void learning(const double& x, const double& y,const double& y1) override;
	double getw();
private: 
 	double w=1;
};
class bias : public Neural
{
public:
	bias(){};
	double function(const double& x) const override;
	double derivate(const double& x)   const override;
	void learning(const double& x, const double& y,const double& y1) override;
	double getb();
private: 
   double b=0;
 
};
}
