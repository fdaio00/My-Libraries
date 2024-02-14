#pragma once
#pragma warning (disable : 4996)
#include<iostream>
#include<string>
using namespace std;
namespace feDateLib 
{

	struct sDate
	{
		short Year;

		short Month;
		short Day;
	};

	string NumberToText(int Number)
	{

		if (Number >= 0 && Number <= 19)
		{
			string arr[] = { "","One","Two","Three",
			"Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve",
			"Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Nineteen" };

			return arr[Number];
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twinty","Thirty",
			"Fourty","Fivty","Sixty","Seventy","Eighty","Ninety" };

			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One handred " + NumberToText(Number % 100);


		}
		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + " handred " + NumberToText(Number % 100);

		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thausand " + NumberToText(Number % 1000);

		}
		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + " Thausand " + NumberToText(Number % 1000);

		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million" + NumberToText(Number % 1000000);

		}
		if (Number >= 2000000 && Number <= 9999999)
		{
			return NumberToText(Number / 1000000) + "  Million" + NumberToText(Number % 1000000);

		}if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion" + NumberToText(Number % 1000000000);

		}
		else
		{
			return NumberToText(Number / 1000000000) + "Billion" + NumberToText(Number % 1000000000);

		}
	}

	bool IsLeapYear(short Year)
	{

		return (Year % 400 == 0 && (Year % 100) != 0) || (Year % 4 == 0);

	}

	/*struct stYear {
		int NumberOfDays;
		int Year;
		int NumberOfHouers;
		int NumberOfSeconds;
		int NumberOfMinutes;
	};

	stYear NumberOfMonthsDaysHouersSecondInYear(int Year)
	{
		stYear sYear;
		if (IsLeapYear(Year))
		{
			sYear.Year = Year;
			sYear.NumberOfDays = 366;
			sYear.NumberOfHouers = sYear.NumberOfDays * 24;
			sYear.NumberOfMinutes = sYear.NumberOfHouers * 60;
			sYear.NumberOfSeconds = sYear.NumberOfMinutes * 60;
		}
		else
		{
			sYear.Year = Year;
			sYear.NumberOfDays = 365;
			sYear.NumberOfHouers = sYear.NumberOfDays * 24;
			sYear.NumberOfMinutes = sYear.NumberOfHouers * 60;
			sYear.NumberOfSeconds = sYear.NumberOfMinutes * 60;
		}
		return sYear;
	}

	void PrintNumberOfDaysHouersSecondsInYear(stYear sYear)
	{
		cout << "\nNUmber of days in the year of [" << sYear.Year << "]  = " << sYear.NumberOfDays << endl;
		cout << "NUmber of houers in the year of [" << sYear.Year << "]  = " << sYear.NumberOfHouers << endl;
		cout << "NUmber of Minutes in the year of [" << sYear.Year << "]  = " << sYear.NumberOfMinutes << endl;
		cout << "NUmber of seconds in the year of [" << sYear.Year << "]  = " << sYear.NumberOfSeconds << endl;
	}
	*/
	int ReadYear()
	{
		int Year = 0;
		cout << "\nEnter a Year To Check : ";
		cin >> Year;
		cout << '\n';

		return Year;
	}

	short ReadMonth()
	{
		short Month = 0;


		cout << "\nEntr Month : ";
		cin >> Month;
	

		return Month;
	}

	short ReadDay()
	{
		short Day = 0;


		cout << "Enter Day : ";
		cin >> Day;
		

		return Day;
	}

	short NumberOfDays(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	int NumberOfHours(short Year)
	{
		return NumberOfDays(Year) * 24;
	}

	int NumberOfMinuets(short Year)
	{
		return NumberOfHours(Year) * 60;
	}

	int NumberOfSeconds(short Year)
	{
		return NumberOfMinuets(Year) * 60;
	}

	void PrintNumberOfDaysHouersMinuetsSecondsInYear(short Year)
	{
		cout << "\nNumber of days in [" << Year << "] = ";
		cout << NumberOfDays(Year) << endl;
		cout << "\nNumber of houers in [" << Year << "] = ";
		cout << NumberOfHours(Year) << endl;
		cout << "\nNumber of Minuets in [" << Year << "] = ";
		cout << NumberOfMinuets(Year) << endl;
		cout << "\nNumber of seconds in [" << Year << "] = ";
		cout << NumberOfSeconds(Year) << endl;





	}

	short NumberOfDaysInAMonth(short Year, short Month)
	{
		if (Month < 1 || Month >12)
		{
			return 0;
		}

		short NumberOfDays[12] = { 31,28,30,31,30,31,31,30,31,30,31,31 };
		return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : NumberOfDays[Month - 1];

	}

	int NumberOfHoursInAMonth(short Year, short Month)
	{
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}

	int NumberOfMinuetsInAMonth(short Year, short Month)
	{
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}

	int NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinuetsInAMonth(Year, Month) * 60;
	}

	void PrintNumberOfDaysHouersMinuetsSecondsInAMonth(short Year, short Month)
	{
		cout << "\nNumber of days in [" << Month << "] = ";
		cout << NumberOfDaysInAMonth(Year, Month) << endl;
		cout << "\nNumber of houers in [" << Month << "] = ";
		cout << NumberOfHoursInAMonth(Year, Month) << endl;
		cout << "\nNumber of Minuets in [" << Month << "] = ";
		cout << NumberOfMinuetsInAMonth(Year, Month) << endl;
		cout << "\nNumber of seconds in [" << Month << "] = ";
		cout << NumberOfSecondsInAMonth(Year, Month) << endl;





	}

	short DayOfWeekOrder(int Year, short Month, short Day)
	{

		int a = (14 - Month) / 12;
		int y = Year - a;
		int m = Month + (12 * a) - 2;

		int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;

	}

	short DayOfWeekOrder(sDate Date)
	{

		int a = (14 - Date.Month) / 12;
		int y = Date.Year - a;
		int m = Date.Month + (12 * a) - 2;

		int d = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;

	}

	string DayShortName(short DayOfWeekOrder) 
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; 
		return arrDayNames[DayOfWeekOrder]; 
	}

	string MonthShortName(short Month)
	{

		string arr[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec" };
		return arr[Month-1 ];
	}

	void PrintMonthCalendar(int Year, short Month)
	{

		short NumberOfDays =0;
		NumberOfDays = NumberOfDaysInAMonth(Year, Month);
		int currernt = DayOfWeekOrder(Year, Month, 1);

		printf("\n----------------%s-----------------\n\n", MonthShortName(Month).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		int i = 0;
		for (i = 0; i < currernt; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}


		}

		cout << "\n-------------------------------------\n";

	}

	void PrintYearCalandar(short Year)
	{



		printf("\n---------------------------------------------\n");
		cout << "\t\tCalandar " << Year << endl;
		printf("\n---------------------------------------------\n");
		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(Year, i);
		}

	}

	short NumberOfDaysFromTheBegningOfTheYear(short Year, short Month, short Days)
	{
		short Total = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			Total += NumberOfDaysInAMonth(Year, i);

		}

		Total += Days;

		return Total;




	}


	sDate GetDateByDayOrder(short DaysOeder, short Year)
	{
		sDate Date;
		short RemainingDays = DaysOeder;
		short Month = 0;

		Date.Month = 1;
		Date.Year = Year;

		while (true)
		{

			Month = NumberOfDaysInAMonth(Year, Date.Month);
			if (RemainingDays > Month)
			{
				RemainingDays -= Month;
				Date.Month++;

			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;



	}

	sDate ReadFullDate()

	{

		sDate Date;
		
		
		Date.Day = ReadDay();
		Date.Month = ReadMonth();
		Date.Year = ReadYear();

		return Date;
	}

	short ReadDaysToAdd()
	{

		short Number = 0;
		cout << "Enter number of days that you want to add to the date: ";
		cin >> Number;

		return Number;
	}

	sDate DateAddDays(sDate Date, short NumberDays)
	{

		short NewDays = NumberDays + NumberOfDaysFromTheBegningOfTheYear(Date.Year, Date.Month, Date.Day);
		short Month = 0;
		Date.Month = 1;



		while (true)
		{
			Month = NumberOfDaysInAMonth(Date.Year, Date.Month);

			if (NewDays > Month)
			{
				NewDays -= Month;
				Date.Month++;
				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}

			else
			{
				Date.Day = NewDays;
				break;
			}
		}

		return Date;
	}

	bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
	{
		return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false); 
	}
	bool IsDate1EqualDate2(sDate Date1, sDate Date2) 
	{
		return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false; 
	}

	bool IsLastDayInMonth(sDate Date)
	{

		return (NumberOfDaysInAMonth(Date.Year, Date.Month) == Date.Day) ? true : false;
	}

	bool IsLastMonthInYear(sDate Date)
	{
		return (Date.Month == 12);
	}

	//sDate IncraseDateByOneDay(sDate Date)
	//{
	//	if (IsLastDayInMonth(Date))
	//	{
	//		if (IsLastMonthInYear(Date))
	//		{
	//			Date.Month = 1;
	//			Date.Day = 1;
	//			Date.Year++;
	//		}
	//		else
	//		{
	//			Date.Day = 1;
	//			Date.Month++;
	//		}
	//	}
	//	else
	//	{
	//		Date.Day++;
	//	}
//	return Date;
	//}
	sDate IncreaseDateByOneDay(sDate Date) {
		if (IsLastDayInMonth(Date)) {
			if (IsLastMonthInYear(Date)) {
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else {
				Date.Day = 1;
				Date.Month++;
			}
		}
		else {
			Date.Day++;
		}
		return Date;
	}

	sDate IncreaseDateByXDays(short Days, sDate Date) {
		for (short i = 1; i <= Days; i++) {
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate IncreaseDateByOneWeek(sDate Date) {
		for (int i = 1; i <= 7; i++) {
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate IncreaseDateByXWeeks(short Weeks, sDate Date) {
		for (short i = 1; i <= Weeks; i++) {
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	sDate IncreaseDateByOneMonth(sDate Date) {
		if (Date.Month == 12) {
			Date.Month = 1;
			Date.Year++;
		}
		else {
			Date.Month++;
		}
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth) {
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	sDate IncreaseDateByXMonths(short Months, sDate Date) {
		for (short i = 1; i <= Months; i++) {
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	sDate IncreaseDateByOneYear(sDate Date) {
		Date.Year++;
		return Date;
	}

	sDate IncreaseDateByXYears(short Years, sDate Date) {
		for (short i = 1; i <= Years; i++) {
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	sDate IncreaseDateByXYearsFaster(short Years, sDate Date) {
		Date.Year += Years;
		return Date;
	}

	sDate IncreaseDateByOneDecade(sDate Date) {
		Date.Year += 10;
		return Date;
	}

	sDate IncreaseDateByXDecades(short Decade, sDate Date) {
		for (short i = 1; i <= Decade * 10; i++) {
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	sDate IncreaseDateByXDecadesFaster(short Decade, sDate Date) {
		Date.Year += Decade * 10;
		return Date;
	}

	sDate IncreaseDateByOneCentury(sDate Date) {
		Date.Year += 100;
		return Date;
	}

	sDate IncreaseDateByOneMillennium(sDate Date) {
		Date.Year += 1000;
		return Date;
	}

	void SwapDates(sDate& Date1, sDate& Date2) {

		sDate TempDate;
		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;

		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;

		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;


	}

	int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		while (IsDate1LessThanDate2(Date1, Date2))
		{
			Days++; 
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return (IncludeEndDay) ? ++Days : Days;
	}

//int GetDifferenceInDays( sDate Date1,  sDate Date2, bool IncludeEndDay = false) {
//		int Days = 0;
//		short SwapFlagValue = 1;
//		Date1;
//
//		if (!IsDate1LessThanDate2(Date1, Date2))
//		{
//			// Swap Dates
//			SwapDates(Date1, Date2);
//			SwapFlagValue = -1;
//		}
//
//		while (IsDate1LessThanDate2(Date1, Date2))
//		{
//			Days++;
//			Date1 = IncreaseDateByOneDay(Date1);
//		}
//		
//
//		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
//	}

	sDate GetSystemDate()
	{

		sDate Date;

		time_t t = time(0);
		tm* now = localtime(&t);

		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}

	int GetAgeByDays(sDate Date1, sDate Date2)
	{

		return GetDifferenceInDays(Date1, Date2, true);
	}

	bool IsFirstDayInMonth(sDate Date)
	{

		return (Date.Day == 1) ? true : false;
	}

	bool IsFirstMonthInYear(sDate Date)
	{

		return (Date.Month == 1) ? true : false;
	}

	sDate DecreaseDateByOneDay(sDate Date) {
		if (IsFirstDayInMonth(Date)) {
			if (IsFirstMonthInYear(Date)) {
				Date.Month = 12;
				Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
				Date.Year--;
			}
			else {
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);

			}
		}
		else {
			Date.Day--;
		}
		return Date;
	}

	sDate DecreaseDateByXDays(short Days, sDate Date) {
		for (short i = 1; i <= Days; i++) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate DecreaseDateByOneWeek(sDate Date) {
		for (int i = 1; i <= 7; i++) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate DecreaseDateByXWeeks(short Weeks, sDate Date) {
		for (short i = 1; i <= Weeks; i++) {
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	sDate DecreaseDateByOneMonth(sDate Date) {
		if (Date.Month == 1) {
			Date.Month = 12;
			Date.Year--;
		}
		else {
			Date.Month--;
		}
		//30/3/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > NumberOfDaysInCurrentMonth) {
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	sDate DecreaseDateByXMonths(short Months, sDate Date) {
		for (short i = 1; i <= Months; i++) {
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	sDate DecreaseDateByOneYear(sDate Date) {
		Date.Year--;
		return Date;
	}

	sDate DecreaseDateByXYears(short Years, sDate Date) {
		for (short i = 1; i <= Years; i++) {
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	sDate DecreaseDateByXYearsFaster(short Years, sDate Date) {
		Date.Year -= Years;
		return Date;
	}

	sDate DecreaseDateByOneDecade(sDate Date) {
		Date.Year -= 10;
		return Date;
	}

	sDate DecreaseDateByXDecades(short Decade, sDate Date) {
		for (short i = 1; i <= Decade * 10; i++) {
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	sDate DecreaseDateByXDecadesFaster(short Decade, sDate Date) {
		Date.Year -= Decade * 10;
		return Date;
	}

	sDate DecreaseDateByOneCentury(sDate Date) {
		Date.Year += 100;
		return Date;
	}

	sDate DecreaseDateByOneMillennium(sDate Date) {
		Date.Year -= 1000;
		return Date;
	}

	bool IsEndOfAWeek(sDate Date)
	{

		string DaysName = DayShortName(DayOfWeekOrder(Date));
		return (DaysName == "Sat") ? true : false;
	}

	bool IsWeekend(sDate Date)
	{

		short DaysIndex = DayOfWeekOrder(Date);
		return (DaysIndex == 5 || DaysIndex == 6);

	}

	bool IsBusinessDay(sDate Date)
	{

		return (!IsWeekend(Date));

	}

	int DaysUntilEndOfWeek(sDate Date)
	{
		return  6 - DayOfWeekOrder(Date);
	}

	int DaysUntilEndOfMonth(sDate Date1)
	{

		sDate EndOfMontDate;
		EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Year, Date1.Month);
		EndOfMontDate.Month = Date1.Month;
		EndOfMontDate.Year = Date1.Year;
		return GetDifferenceInDays(Date1, EndOfMontDate, true);

	}

	int DaysUntilEndOfYear(sDate Date)
	{
		sDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;
		return GetDifferenceInDays(Date, EndOfYearDate, true);
	}

	short CalculateActualVicationDays(sDate StartDate, sDate EndDate)
	{

		short NumberOfVications = 0;

		while (IsDate1LessThanDate2(StartDate, EndDate))
		{
			if (IsBusinessDay(StartDate))
			{
				NumberOfVications++;
			}

			StartDate = IncreaseDateByOneDay(StartDate);

		}

		return NumberOfVications;

	}

	short ReadNumberOfVicationDays()
	{

		short Number = 0;
		cout << "Enter Number of Vication Dates : ";
		cin >> Number;

		return Number;
	}

	sDate CalculateVicationReturnDate(sDate Date, short NumberOfVicationDays)
	{
		while (NumberOfVicationDays != 0)
		{
			if (IsBusinessDay(Date))
			{
				NumberOfVicationDays--;
			}
			Date = IncreaseDateByOneDay(Date);

		}

		return Date;

	}
	
	bool IsDate1MoreThanDate2(sDate Date1, sDate Date2)
	{


		return (!(IsDate1LessThanDate2(Date1, Date2)) && !(IsDate1EqualDate2(Date1, Date2)));
	}

	enum enCompareResults { Equal = 0, Less = -1, More = 1 };

	enCompareResults CompareDatesResults(sDate Date1, sDate Date2)
	{
		if (IsDate1EqualDate2(Date1, Date2))
			return enCompareResults::Equal;
		else if (IsDate1LessThanDate2(Date1, Date2))
			return enCompareResults::Less;
		else
			return enCompareResults::More;
	}

	struct sPeriod
	{
		sDate StartDate;
		sDate EndDate;
	};

	bool IsOverlapPeriods(sPeriod Period1, sPeriod Period2)
	{
		if (CompareDatesResults(Period2.EndDate, Period1.StartDate) == enCompareResults::Less
			||
			CompareDatesResults(Period2.StartDate, Period1.EndDate) == enCompareResults::More
			)
		

			return false;
		
		 
		return true;

	}

	sPeriod ReadPeriod()
	{
		sPeriod Period;
		Period.StartDate = ReadFullDate();
		Period.EndDate = ReadFullDate();

		return Period;
	}

	short CalculateLengthPeriod(sPeriod Period, bool IncludeEndDay = false)
	{


		return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	bool IsDateInPeriod(sPeriod Period, sDate Date)
	{

		return !(CompareDatesResults(Date, Period.StartDate) == enCompareResults::Less
			||
			CompareDatesResults(Date, Period.EndDate) == enCompareResults::More);

	}

	short CountOverlapDays(sPeriod Period1, sPeriod Period2)
	{
		short LapDays = 0;
		short Lenth1 = CalculateLengthPeriod(Period1);
		short Lenth2 = CalculateLengthPeriod(Period2);
		if (!IsOverlapPeriods(Period1, Period2))
		{
			return 0;

		}

		if (Lenth1 < Lenth2)
		{

			while (IsDate1LessThanDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateInPeriod(Period2, Period1.StartDate))
					LapDays++;

				Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
			}
		}

		else
		{
			while (IsDate1LessThanDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateInPeriod(Period1, Period2.StartDate))
					LapDays++;

				Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
			}


		}

		return LapDays;

	}

	void sy()
	{
		system("pause>0");
	}

	bool ValidateDate(sDate Date)
	{
		short Days = 0;
		if (NumberOfDaysInAMonth(Date.Year, Date.Month) == 0)
		{
			return 0;
		}

		Days = NumberOfDaysInAMonth(Date.Year, Date.Month);



		return (Days > Date.Day);


	}















	vector<string> SplitString(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}

	string DatetToString(sDate Date)
	{
		string Seperator = "/";
		string stringDate = "";

		stringDate += to_string(Date.Day) + Seperator;
		stringDate += to_string(Date.Month) + Seperator;
		stringDate += to_string(Date.Year);

		return stringDate;


	}
	sDate StringToDate(string DateString, string Seperator = "/")
	{

		sDate Date;
		vector<string> vDate;

		vDate = SplitString(DateString, Seperator);

		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);


		return Date;

	}

	string ReadDateString()
	{
		string Date = "";
		cout << "Enter Date : ";
		getline(cin >> ws, Date);
		return Date;
	}


	string ReplaceWordInString(string S1, string StringToReplace, string ReplaceTo) {
		size_t pos = S1.find(StringToReplace);
		while (pos != string::npos) {
			S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
			pos = S1.find(StringToReplace, pos + ReplaceTo.length()); // find next
		}
		return S1;
	}

	string FormatDate(sDate Date, string DateFormat = "dd/mm/yyyy") {
		string FormattedDateString = "";
		FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
		FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
		FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
		return FormattedDateString;
	}
}
