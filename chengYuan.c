#include<iostream>
using namespace std;

static int   leap[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
static int unleap[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

class Date
{
private:
	int year,month,day;

public:
	Date(int _year,int _month,int _day):year(_year),month(_month),day(_day){
		if(_year<0||(_month<1||_month>12)||(day<1||day>The_day_of_month(_year,_month))){
			year=1980;
			month=day=1;
		}
	}
	~Date(){}
	bool isleap(int year)const{
		return year%4==0&&year%100!=0||year%400==0?true:false;
	}
	int The_day_of_month(int year,int month){
		return isleap(year)?leap[month]:unleap[month];
	}
	bool inPeriod(Date & d1 , Date &d2){
		return (*this>=d1&&*this<=d2)||(*this>=d2&&*this<=d1)?true:false;
	}
	friend istream & operator>>(istream & cin,Date &d){
		cin>>d.year>>d.month>>d.day;
	}
	friend ostream & operator<<(ostream & cout,const Date &d){
		cout<<d.year<<"-"<<d.month<<"-"<<d.day<<endl;
	}
	void operator = (Date & d){
		year=d.year;
		month=d.month;
		day=d.day;
	}
	
	Date operator +(int _day){
		Date tt(year,month,day);
		while(_day){
			int month_day=isleap(tt.year)?leap[tt.month]:unleap[tt.month];
			if(_day>month_day){
				tt.day=1;
				_day-=month_day;
				tt.month++;
				if(tt.month>12){
					tt.month=1;
					tt.year++;
				}
			}
			else{
				tt.day+=_day;
				_day=0;
			}
		}
		return tt;
	}

	int operator - 

    void operator =

    bool operator < 

    bool operator >= 

    bool operator > 


    bool operator <= 


    bool operator == 


    bool operator != 

	const getyear()const{
		return year;
	}
	const getmonth()const{
		return month;
	}
	const getday()const{
		return day;
	}
	bool setyear(int _year){
		if(_year>0){
			year=_year;
			return true;
		}
		return false;
	}
	bool setmonth(int _month){
		if(_month>0){
			month=_month;
			return true;
		}
		return false;
	}
	bool setday(int _day){
		if(_day>0){
			day=_day;
			return true;
		}
		return false;
	}
};


int main()
{
	return 0;
}