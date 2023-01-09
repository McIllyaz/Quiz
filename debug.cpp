#include <iostream>
#include <conio.h>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
#define compareBoxes(box1, box2, box3) ((board[box1] == board[box2]) && (board[box2] == board[box3]) && (board[box1] != 0)) //Checkes if three items are the same, and makes sure they're not 0's.
#define numberToLetter(x) ((x > 0) ? (x == 1) ? 'X' : 'O' : ' ') //Takes the number and turns it into the letter or space.

string nama, prodi;
char yt;
int plh;
int getWinner(int board[9]) {
	//Finds winner of game, if there is no winner, returns 0.
	int winner = 0;
	for (int x = 0; x < 3; x++) {
		if (compareBoxes(3*x, 3*x+1, 3*x+2)) { //Chekcs rows.
			winner = board[3*x];
			break;
		} else if (compareBoxes(x, x+3, x+6)) { //Checks columns.
			winner = board[x];
			break;

		} else if (compareBoxes(2*x, 4, 8-2*x) && (x < 2)) { //Checks diagonals. Doesn't check if x == 2.
			winner = board[4];
			break;
		}
	}
	return winner;
}
bool gameOver(int board[9]){
	//Checks if game is over, and announces who won, or if it was a tie.
	int winner = getWinner(board);
	if (winner > 0) {
		cout << numberToLetter(winner) << " wins!"<< endl;
		return true;
	} 
	for (int x = 0; x < 9; x++) {
		if (board[x] == 0) return false;
	}
	cout << "Tie!\n\n";
	return true;
}

int willWin(int board[9], int player) {
	//Checks if a given player could win in the next plank.
	for (int x = 0; x < 9; x++) {
		int tempBoard[9];
		memcpy(tempBoard, board, 36);
		if (board[x] > 0) continue;
		tempBoard[x] = player;
		if(getWinner(tempBoard) == player) return x;
	}
	return -1;
}

int exceptionalCase(int board[9]) {
	//Finds bords that are exceptions to how the algorithm works.
	int cases[2][9] = {{1,0,0,0,2,0,0,0,1}, {0,1,0,1,2,0,0,0,0}}; //Boards that don't work with algorithm.
	int answers[2][4] = {{3,3,3,3}, {2,8,6,0}};
	int rotatedBoard[9] = {6,3,0,7,4,1,8,5,2};
	int newBoard[9];
	int tempBoard[9];
	for(int x = 0; x < 9; x++) {
		newBoard[x] = board[x];
	}
	for (int caseIndex = 0; caseIndex < 2; caseIndex++) {
		for(int rotation = 0; rotation < 4; rotation++) {
			for (int x = 0; x < 9; x++) 
				tempBoard[x] = newBoard[x];
			
			int match = 0;
			//Rotates board so it works with different versions of the same board.
			for (int box = 0; box < 9; box++) {
				newBoard[box] = tempBoard[rotatedBoard[box]];
			}

			for (int x = 0; x < 9; x++) {
				if (newBoard[x] == cases[caseIndex][x]) match++;
				else break;
			}
			if (match == 9) return answers[caseIndex][rotation];
		}
	}
	return -1;
}

int getSpace(int board[9], int spaces[4]) {
	//Gets a random corner or side that's not taken.
	bool isSpaceEmpty = false;
	int y;
	for (int x = 0; x < 4; x++) {
		if (board[spaces[x]] == 0) {
			isSpaceEmpty = true;
			break;
		}
	}
	if (isSpaceEmpty) {
		do {
			y = rand() % 4;
		} while (board[spaces[y]] != 0);
		return spaces[y];
	}
	return -1;
}

void outputBoard(int board[9]) {
	for(int line = 0; line < 3; line++){
		for (int box = 0; box < 3; box++) {
			cout << numberToLetter(board[3*line+box]) << ((box < 2) ? '|' : '\n');
		}
		cout << ((line < 2) ? "-----\n" : "\n");
	}
}

int soal2(){
   
    string questions_dua[5] = {
    "Dibawah ini yang merupakan bagian dari sistem operasi, kecuali",
    "Perangkat yang terdapat dalam sistem komputer diantaranya adalah",
    "Fungsi alat ini ialah untuk memindai data atau dokumen dengan cara menduplikasi dalam bentuk digital atau file dalam komputer. Alat ini termasuk jenis hardware",
    "Perangkat lunak uji coba yang diberikan secara gratis dengan keterbatasan fitur-fitur tertentu seperti ketersediaan, fungsi, dan kenyaman yang tidak dapat dimanfaatkan secara maksimal ialah",
    "Kelompok 2: Hardisk, flash disk, CD/DVD, SSD Kelompok 3: Monitor, printer, speaker, plotter Kelompok 4: RAM, processor, VGA card, \nmainboard Yang termasuk ke dalam perangkat keras keluaran adalah", };

    string option_dua[5][4] = { 
        {"Kelompok 1", "Kelompok 2", "Kelompok 3", "Kelompok 4"},
        {"Commercial Software", "Shareware", "Freeware", "Openware"},
        {"Input device", "Output device", "Storage device", "Processing device"},
        {"Hardware, program dan CPU", "Software, Brainware dan Linux", "User, program dan perangkat lunak", "Hardware, software dan brainware"},
        {"CPU", "Linux", "Mac OS", "DOS"}
        };

    string correct_ans_dua[5]{
        "Kelompok 3", "Freeware", "Processing device", "Hardware, software dan brainware", "CPU",
    };
    int selected_option_dua[5] = {0, 0, 0, 0, 0};
	int totalQ = 5;
	int op;

    soal2: 
    cout << "\n====================================================================================\n";
    cout << "Apakah anda ingin mengerjakan soal sekarang? (y/t)\n";
    cin >> yt;
    cout << "====================================================================================\n";


    if (yt == 't' || yt == 'T')
    {
        exit(0);
	}else if (yt == 'y' || yt == 'Y'){
        for(int j = 0; j < totalQ; j++){
            cout << "Question No: " << (j+1) << endl;
            cout << questions_dua[j] << endl;
            cout << "1." <<  option_dua[j][0] << endl;
            cout << "2." <<  option_dua[j][1] << endl;
            cout << "3." <<  option_dua[j][2] << endl;
            cout << "4." <<  option_dua[j][3] << endl << endl;

            cout << "0 is for skip. Select your answer as 1, 2, 3 or 4 here : ";
            cin >> selected_option_dua[j];
            cout << endl << "==========================================================" << endl << endl;
        }

        system("cls");
        cout << "********************************* " << endl;
        cout << "****** Compare your answer ****** " << endl;
        cout << "********************************* " << endl << endl;

        for(int j = 0; j < totalQ; j++){
            cout << "Question No: " << (j+1) << endl;
            cout << questions_dua[j] << endl;
            cout << "1." << option_dua[j][0] << endl;
            cout << "2." << option_dua[j][1] << endl;
            cout << "3." << option_dua[j][2] << endl;
            cout << "4." << option_dua[j][3] << endl;

            if( selected_option_dua[j] == 0 ){
                cout << "You have Skipped this Question." << endl;
            }else{
                cout << "You have Selected\t: " << option_dua[j][ selected_option_dua[j]-1] << endl;
            }
            cout << "Correct Option was\t: " << correct_ans_dua[j] << endl << endl;

            cout << "Press any key to continue checking..." << endl;
            getch();
            cout << endl << "=============================================" << endl;
        }
        cout << endl << endl;
        cout << "************************************ " << endl;
        cout << "*********** Your Result ************ " << endl;
        cout << "************************************ " << endl << endl;

        int correct = 0;
        int incorrect = 0;
        int skipped = 0;

        for(int j = 0; j < totalQ; j++){
            if(selected_option_dua[j] != 0){
                if(correct_ans_dua[j] == option_dua[j][selected_option_dua[j]-1]){
                    correct++;
                }else{
                    incorrect++;
                }
            }else{
                skipped++;
            }
        }
        cout << "Nama\t\t\t: " << nama << endl;
        cout << "Prodi\t\t\t: " << prodi << endl;
        cout << "Correct answer\t\t: " << correct << endl;
        cout << "Wrong answer\t\t: " << incorrect << endl;
        cout << "Skipped\t\t\t: " << skipped << endl;

        
    }else{
        system("cls");
        cout << "Maaf inputan tidak valid :(" << endl;
        goto soal2;
    }
}
/////////
int main(){

    string all_questions[10] = {    // all the questions
	"Diketahui bahwa kantong P kosong, kantong Q berisi 10 buah kelereng dan kantong R berisi 15 kelereng.\nApabila yang terbawa hanya sebuah kantong dan dikatakan BUKAN Kantong P yang terbawa\nmaka jumlah kelereng yang terbawa adalah :",
	"Diberikan algoritma : \nApabila warna merah maka jadi hijau., \nApabila warna hijau maka jadi putih, \nselain warna merah dan hijau maka jadi ungu. \nJika kondisi input warna adalah hitam, maka warna jadi :",
	"Instruksi P=Q akan mengakibatkan nilai P = nilai Q, dan nilai Q menjadi :",
	"Apabila a=5, b = 10, maka jika diberikan instruksi a=b; b=a akan mengakibatkan ",
	"Diberikan algoritma P=10; P=P+5; Q=P. Nilai P dan Q masing-masing adalah",
	"Type data yang hanya mengenal kondisi True atau False pada Bahasa pemrograman C++ , adalah :",
	"Dalam bahasa C++ terdapat suatu tipe data yang nilainya tidak boleh memiliki nilai desimal, yaitu :",
	"Program C++ dirancang pertama kali oleh :",
	"Tipe data yang digunakan untuk menampung sebuah karakter adalah :",
	"Pada Tipe data Boolean, berlaku operator-operator" };

	string all_options[10][4] = {    // all options
	{"10","10 dan 15","15","10 atau 15"},
	{"Merah","Putih","Ungu","Abu-abu"},
	{"Menjadi sembarang nilai","Menjadi hampa","Q tetap","Menjadi 0"},
	{"a=0, b=5","a=b","a=10, b=5","a=10, b=10"},
	{"15 dan 0","0 dan 10","0 dan 15","15 dan 15"},
	{"Char","Bool","long int","Int"},
	{"Float","Char","Bool","Int"},
	{"Al Khawarizmi","Dennis Ritchie","Blaise Pascal","Al khalamizni"},
	{"String","Int","Char","Boolean"},
	{"IF","AND, OR, NOT","True, False","Case"},
    };

	string correct_ans[10] = {    // correct options
		"10 atau 15","Ungu","Q tetap","a=10, b=10",
		"15 dan 15","Bool","Int",
		"Dennis Ritchie","Char","AND, OR, NOT"
    };

	int selected_option[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int totalQ = 10;
	int op;


    pilih:


    cout << "========================================================\n";
    cout << "Selamat datang di aplikasi quiz:)\nAplikasi ini berisi 10 soal terdiri dari 1 mata kuliah.\nApakah anda ingin mengerjakan soal? (y/t)\n";
    cin >> yt;
    cout << "========================================================\n";


    if (yt =='t' || yt =='T'){
        exit(0);
	}else if(yt =='y' || yt =='Y'){
        cout << "Nama : ";
        cin >> nama;
        cout << "Prodi: ";
        cin >> prodi;
        repetisi:
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
        cout << "Nama\t\t\t: " << nama << endl;
        cout << "Prodi\t\t\t: " << prodi << endl;
        cout << "Correct answer\t\t: " << correct << endl;
        cout << "Wrong answer\t\t: " << incorrect << endl;
        cout << "Skipped\t\t\t: " << skipped << endl;
        cout << "=======================================" << endl;
    }else{
        system("cls");
        cout << "Maaf inputan tidak valid :(" << endl;
        goto pilih;
    }
    
    lagi:
	cout << "Apakah anda ingin mencoba lagi? (1. ulang) (2. soal lain) (3. main game)" << endl;
	cin >> plh;
	if (plh == 1)
	{
		system("cls");
		goto repetisi;
    }
    else if(plh == 2)
    {
       system("cls");
       soal2();
        pilih_lagi :
        cout << "=========================================================" << endl;   
        cout << "Apakah anda ingin mencoba lagi? (1. ulang) (2. main game)" << endl;
	    cin >> plh;
        if (plh == 1){
            system("cls");
            soal2();
            goto pilih_lagi;
        }else if (plh == 2){
            goto game;
        }else{
            system("cls");
            cout << "Maaf Inputan tidak valid :(\n";
            cout << "==============================";
            goto pilih_lagi;
        }
	}
    else if (plh == 3){ 
	game: 
	int board[9] = {0,0,0,0,0,0,0,0,0}; //Starts empty board.
	int possibleWinner;
	int move;
	bool isInvalid;
	string moveString;
	srand((int) time(0));
	int corners[4] = {0,2,6,8};
	int sides[4] = {1,3,5,7};

	cout << "1|2|3\n-----\n4|5|6\n-----\n7|8|9\n\n";
	cout << "Pilih angka 1 - 9 untuk mengisi X" << endl;

	while (true) {
		//Player X decides what move they'll do.
		do {
			cout << "X: ";
			getline(cin, moveString);
			move = moveString[0] - '1';
			if (move > 8 || move < 0 || board[move] != 0) {
				cout << "Giliranmu" << endl;
				isInvalid = true;
			} else {
				board[move] = 1;
				isInvalid = false;
				cout << endl;
			}
		} while (isInvalid);

		//Decides whether or not the game continues.
		if (gameOver(board) > 0) {
			outputBoard(board);
			break;
		}

		//Player O decides which move they'll do.
		bool good = false;
		for (int x = 2; x > 0; x--){
			possibleWinner = willWin(board, x);
			if (possibleWinner != -1) {
				board[possibleWinner] = 2;
				good = true;
				break;
			}
		}
		if (good);
		else if (board[4] == 0) board[4] = 2; //Middle.
		else if (exceptionalCase(board) > -1) board[exceptionalCase(board)] = 2; //Exception boards.
		else if (getSpace(board, corners) != -1) board[getSpace(board, corners)] = 2; //Corners
		else board[getSpace(board, sides)] = 2; //Sides
		
		//Prints the board to the screen.
		outputBoard(board);

		//Decides whether or not the game continues.
		if(gameOver(board)) break;

	}
	cout << "Apakah Anda ingin main lagi? (y/t): \n";
	cin >> yt;
	if (yt =='y' || yt == 'Y')
	{
		system("cls");
		goto game;
	}else if(yt =='t' || yt == 'T')
	{
		cout << "\n\t     Demikian presentasi dari kami\n";
        cout << "\t........................................."<< endl;
        cout << "\t:::::: 000::::::::::::::::::::000::::::::"<< endl;
        cout << "\t:::::: 0000:::::::::::::::::::0000:::::::"<< endl;
        cout << "\t::::::00000::::::::::::::::::000000::::::"<< endl;
        cout << "\t::::::000000:::::::::::::::::000000::::::"<< endl;
        cout << "\t::::::000000:::::::::::::::::000000::::::"<< endl;
        cout << "\t::::::000000:::::::::::::::::000000::::::"<< endl;
        cout << "\t::::::000000:::0000:::0000:::000000::::::"<< endl;
        cout << "\t::::::000000::000000:000000::000000::::::"<< endl;
        cout << "\t::::::000000::000000:000000::000000::::::"<< endl;
        cout << "\t::::::000000::000000:000000::000000::::::"<< endl;
        cout << "\t::::::000000::000000:000000::000000::::::"<< endl;
        cout << "\t::::::000...::......:......::....00......"<< endl;
        cout << "\t::::::000....ooooooooooo'8888 ...00::::::"<< endl;
        cout << "\t::::::00....ooooooooooo'888888...00::::::"<< endl;
        cout << "\t::::::00...ooooooo-oooo '8888....00::::::"<< endl;
        cout << "\t::::::00**oooooo.................00......"<< endl;
        cout << "\t::::::00*oooooo*...............0000......"<< endl;
        cout << "\t::::::00oooooo*...............0000......."<< endl;
        cout << "\t.......0000000...............0000........"<< endl;
        cout << "\t........00000...............00000........"<< endl;
        cout << "\t.........00000.............00000........."<< endl;
        cout << "\t..........0000............00000.........."<< endl;
        cout << "\t...........0000000......00000............"<< endl;
        cout << "\t.................00000000................"<< endl;
		exit(0);
	}
	}else{
        cout << "inputan tidak valid\n";
    }
	getch();
	return 0;
}
