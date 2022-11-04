#include<iostream>
#include<conio.h>
using namespace std;

int main(){
    char yt;

    string all_questions[10] = {    // all the questions
	"Which is the smallest country?",
	"Which is the capital of Argentina?",
	"Which is called world population day?",
	"Who is the first person to draw the map of earth?",
	"Who was the first lady astronaut?",
	"Who is the father of chemistry?",
	"Who is the inventor of Rail Engine?",
	"Which is the capital of America?",
	"Which is not the member of G-8?",
	"Which is the biggest ocean?" };

	string all_options[10][4] = {    // all options
	{"Maldivs","Vatican city","Fizi","Tuvalue"},
	{"Buenes aires","Havana","Tokiyo","None of them"},
	{"5 March","11 july","17 May","12 June"},
	{"Aristotol","Neuton","Anaximander","Thales"},
	{"Tomas alva","George King","Valentina Terescova","Nil Armstrong"},
	{"Thomson","Robert boyel","John Dalton","Demitri Mendelieve"},
	{"Jems watt","Michel Farady","Stiphenson","Kohen"},
	{"Washington Dc","Moscow","Hawaii","California"},
	{"France","Italy","Spain","Jarmany"},
	{"Arctic ocean","Pacific Ocean","Indian ocean","Atlantic"},
    };

	string correct_ans[10] = {    // correct options
		"Vatican city","Buenes aires","11 july","Anaximander",
		"Valentina Terescova","Robert boyel","Stiphenson",
		"Washington DC","Spain","Pacific Ocean"
    };

	int selected_option[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int totalQ = 10;
	int op;

    cout << "\n====================================================================================\n";
    cout << "Selamat datang di aplikasi quiz:)\nAplikasi ini berisi 30 soal terdiri dari 3 mata kuliah dengan masing-masing soal 10.\nApakah anda ingin mengerjakan soal? (y/t)\n";
    cin >> yt;
    cout << "====================================================================================\n";

repetisi:
    if (yt =='y' || yt =='Y')
    {
        system("cls");
        cout << "Oh tidak, ada monster yang akan mengganggu kita. Bantu kami dalam mengalahkannya!\n*hint*\nSetiap jawaban benar yang Anda peroleh akan mendapatkan attack power sebesar 2\n==============================================================================\n";
    }else																							
	{
		exit(0);
	}
    
    for(int i = 0; i < totalQ; i++){
		cout << "Question No: " << (i+1) << endl;
		cout << all_questions[i] << endl;
		cout << "1." << all_options[i][0] << endl;
		cout << "2."<<all_options[i][1] << endl;
		cout << "3." << all_options[i][2] << endl;
		cout << "4." << all_options[i][3] << endl << endl;

		cout << "0 is for skip. Select your answer as 1, 2, 3 or 4 here : ";
		cin >> selected_option[i];
		cout << endl << "==========================================================" << endl << endl;
	}

	//----- Printing Correct Options -----
    system("cls");
	cout << "********************************* " << endl;
	cout << "****** Compare your answer ****** " << endl;
	cout << "********************************* " << endl << endl;

	for(int i = 0; i < totalQ; i++){
		cout << "Question No: " << (i+1) << endl;
		cout << all_questions[i] << endl;
		cout << "1." << all_options[i][0] << endl;
		cout << "2." << all_options[i][1] << endl;
		cout << "3."<< all_options[i][2] << endl;
		cout << "4." << all_options[i][3] << endl;

		if(selected_option[i] == 0 ){
			cout << "You have Skipped this Question." << endl;
		}else{
			cout << "You have Selected\t: " << all_options[i][selected_option[i]-1] << endl;
		}
		cout << "Correct Option was\t: " << correct_ans[i] << endl << endl;

		cout << "Press any key to continue checking..." << endl;
		getch();
		cout << endl << "=============================================" << endl;
	}

	//----- Printing Result -----
	cout << endl << endl;
	cout << "************************************ " << endl;
	cout << "*********** Your Result ************ " << endl;
	cout << "************************************ " << endl << endl;

	int correct = 0;
	int incorrect = 0;
	int skipped = 0;

	for(int i = 0; i < totalQ; i++){
		if(selected_option[i] != 0){
			if(correct_ans[i] == all_options[i][selected_option[i]-1]){
				correct++;
			}else{
				incorrect++;
			}
		}else{
			skipped++;
		}
	}
	cout << "Total questions\t: " << totalQ << endl;
	cout << "Correct answer\t\t: " << correct << endl;
	cout << "Wrong answer\t\t: " << incorrect << endl;
	cout << "Skipped\t\t\t: " << skipped << endl;
	cout << "=======================================" << endl;
	cout << "Apakah anda ingin mencoba lagi? (y/t)" << endl;
	cin >> yt;
	if (yt =='y' || yt =='Y')
	{
		goto repetisi;
	}else
	{
		exit(0);
	}
	
	

	getch();
	return 0;

}