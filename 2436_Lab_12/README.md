# 2436_Lab_12

lab12 - Hash Table Exercise

In this lab, we will use the textbooks implementation of a hash table to implement a states lookup functionality. Included with the lab are a number of files:

500States.txt : this file is a listing of 500Cities.csv. It is a comma separated data file in which each row is a unique data record and the data element of each record is structured as : StateAbbr,PlaceName,PlaceFIPS,Population2010,Geolocation.

readCSVDemo.cpp : this cpp source file implements a short demo application of how to read the 500States.txt data file. You should consider embedding this functionality into your application.

hastT.h : This file contains the textbooks implementation of a hash table.

Your task is to use the hashT code to implement a city lookup functionality in which the city information is stored in the hash table. The recommended approach would be to use the FIPS code ( a unique city identification number ) as the key and an object containing the city information as the value. You'll need to decided on an appropriate hashing function and an appropriate hash table size.

Grading Rubric:
1. Your application must compile to earn any points. 
2. It must successfully store each of the 500 city records for 50% of available points
3. It must successfully be able about to lookup a city record based on the FIPS code for the reminder of available points.

Please include a test listing the demonstrate successful accomplishment of all 3 requirements.

Note : Even though the FIPS is all digits, it would be a bad design to set its data type as numeric ( int ) - it should be stored as a string because there will never be any arithmetic performed on FIPS numbers. On the other hand, population should be stored as numeric data so that some arithmetic ( i.e. population growth percentage ) can be performed.
