/*
 * arrayEmployees.h
 *
 *
 * Author: Blanco Julian Agustin
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


#define SECTOR_MAX 7
#define LONG_NAME 51
#define LONG_LASTNAME 51


typedef struct{
	int id;
	char name[LONG_NAME];
	char lastName[LONG_LASTNAME];
	float salary;
	int sector;
	int isEmpty;
}Employee;


int requestDataEmployee(Employee* auxEmployee);
int initEmployees(Employee* list, int len);
int addEmployees(Employee* list, int len, char* name, char* lastName, float salary, int sector);
int findEmployeeById(Employee* list, int len, int id, int* pIndex);
int modifyEmployee(Employee* list, int len, Employee aux, int index, int field);
int removeEmployee(Employee* list, int len, int id);
int printEmployees(Employee* list, int len);

int searchFreePlaceEmployee(Employee* list, int len, int* pIndex);
int searchOccupiedPlaceEmployee(Employee* list, int len);
int sortEmployeesByLastNameSector(Employee* list, int len, int order);

int AccumulateAverageSalary(Employee* list, int len, float* pAccumulator, float* pAverage);
int calculateEmployeesOverAverageSalary(Employee* list, int len, int* pCounter, float average);


#endif /* ARRAYEMPLOYEES_H_ */
