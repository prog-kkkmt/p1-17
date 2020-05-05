#ifndef REALIZE_H_INCLUDED
#define REALIZE_H_INCLUDED
#include <iostream>

/**=====================================================================================================================**/
/** student **/

void student :: PrintAllInformation(size_t k){
    std::cout<<"������� ���������� � �������� "<<name<<"     "<<second_name<<"     "<<father_name<<"     "<<KolAbsenteeisms<<"     "<<Estimation<<std::endl;
    std::cout<<"�������: ";
    for(size_t i=0; i<k; i++)
        std::cout<<_absenteeisms[i]<<" ";
	std::cout<<"������: "<< std::endl;
	for(size_t i=0; i<k; i++)
        std::cout<<EstimationDay[i];
    std::cout<< std::endl;
}

std::ostream& operator<< (std::ostream &out, const student &person){
	std::cout<<person.name<<"     "<<person.second_name<<"     "<<person.father_name<<"     "<<person.KolAbsenteeisms<<"     "<<person.Estimation<<std::endl;
}

void student::AppendDay(size_t days){
	char c;
	bool * tmp_absenteeisms = _absenteeisms;
    int * tmp_EstimationDay = EstimationDay;
    delete [] _absenteeisms;
    delete [] EstimationDay;
	_absenteeisms = new bool[days];
	EstimationDay = new int[days];

	_absenteeisms = tmp_absenteeisms;
    EstimationDay = tmp_EstimationDay;
	do{
		std::cout<<"��� ������� "<< second_name<< " �� ����? y - ��, n - no  -  ";
		std::cin.get(c);
        std::cin.get(c);
	}while(!(c=='y' || c=='Y' || c=='n' || c=='N'));
    if(c=='y' || c=='Y')
		_absenteeisms[days - 1] = false;
	else{
		_absenteeisms[days - 1] = true;
		KolAbsenteeisms++;
	}
	do{
		if(!_absenteeisms[days - 1]){
			std::cout<<"������� ������ �������� "<< second_name<< ". �� 2 �� 5 (0-��������� ������)  -  ";
			std::cin>>EstimationDay[days - 1];
		}
		else
			EstimationDay[days - 1]=0;
	}while(!((EstimationDay[days - 1]>=2 && EstimationDay[days - 1]<=5) || EstimationDay[days - 1]==0));
    Estimation = (Estimation * (days-1) + EstimationDay[days - 1]) / days;
}
void group::sorted(size_t flag){
    if(flag==0){
        for(size_t i=0; i<this->_size-1; i++)
			for(size_t j=i; j<this->_size; j++)
                if(this->persons[i].name>this->persons[j].name)
					SwapAll(persons[i], persons[j]);
				else if(this->persons[i].second_name>this->persons[j].second_name)
					SwapAll(persons[i], persons[j]);
				else if(this->persons[i].father_name>this->persons[j].father_name)
					SwapAll(persons[i], persons[j]);
	}
	else if(flag==1){
        for(size_t i=0; i<this->_size-1; i++)
			for(size_t j=i; j<this->_size; j++)
                if(this->persons[i].KolAbsenteeisms<this->persons[j].KolAbsenteeisms)
					SwapAll(persons[i], persons[j]);
	}
	else if(flag== -1){
		for(size_t i=0; i<this->_size-1; i++)
			for(size_t j=i; j<this->_size; j++)
                if(this->persons[i].Estimation<this->persons[j].Estimation)
					SwapAll(persons[i], persons[j]);
	}
}

/**=====================================================================================================================**/
/** group **/

void group :: PrintAllInformation(){
	std::cout<<"���������� ���� - "<<day<<std::endl;
	std::cout<<"���������� ����� - "<<_size<<std::endl;
	for(size_t i=0; i<_size; i++)
		persons[i].PrintAllInformation(day);
}


std::ostream& operator<< (std::ostream &out, const group &person){
	std::cout<<"��� \ ������� \ �������� \ ���������� �������� \ ������ �������"<<std::endl;
	std::cout<<"=========================================================================================================="<<std::endl;
    for(size_t i=0; i<person._size; i++){
		std::cout<<person.persons[i];
		std::cout<<"=========================================================================================================="<<std::endl;
    }
	std::cout<<"=========================================================================================================="<<std::endl;
}


void group::SwapAll(student &ob1, student &obj2){
	swap(ob1.name, obj2.name);
	swap(ob1.second_name, obj2.second_name);
	swap(ob1.father_name, obj2.father_name);
	double tmp = ob1.Estimation;

	ob1.Estimation = obj2.Estimation;
	obj2.Estimation = tmp;

	int Itmp = ob1.KolAbsenteeisms;
	ob1.KolAbsenteeisms = obj2.KolAbsenteeisms;
	obj2.KolAbsenteeisms = Itmp;
	bool Btmp;
	for(size_t i = 0; i<day; i++){
        Itmp = ob1.EstimationDay[i];
		ob1.EstimationDay[i] = obj2.EstimationDay[i];
		obj2.EstimationDay[i] = Itmp;

		Btmp = ob1._absenteeisms[i];
		ob1._absenteeisms[i] = obj2._absenteeisms[i];
		obj2._absenteeisms[i] = Btmp;
	}
}

void group::NewDay(){
	this -> day++;
    for(size_t i=0; i<this -> _size; i++)
		persons[i].AppendDay(day);

}

std::fstream& operator << (std::ofstream &os, const group &person){
	os<<"���- "<<person.day<<" .��������- "<<person._size<<std::endl;
	for(size_t i =0; i<person._size; i++){
		os<<"���: "<<person.persons[i].name<<" "<<person.persons[i].second_name<<" "<<person.persons[i].father_name<<std::endl;
		os<<"�������: ";
			for(size_t j =0; j<person.day; j++){
				os<<person.persons[i]._absenteeisms[j]<<" ";
			}
			os<<std::endl;
			os<<"������: ";
			for(size_t j =0; j<person.day; j++){
				os<<person.persons[i].EstimationDay[j]<<" ";
			}
			os<<std::endl;
	}
}
#endif // REALIZE_H_INCLUDED
