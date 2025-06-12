#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <limits>
using namespace std;

int vd; // 프로그램 전체적으로 사용되는 입력 대기 변수, 하지만 지역 변수로 대체 가능

// 공통 함수: 엔터 대기
void waitForInput() {
    cout << endl << "초기 화면으로 이동하려면 아무 숫자나 입력하세요: ";
    int dummy;
    cin >> dummy;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// 공통 함수: 임시 입력 대기 (추가/삭제 등 다른 메시지용)
void waitForInputWithMessage(const string& msg = "다음으로 넘어가려면 아무 숫자나 입력하세요: ") {
    cout << endl << msg;
    int dummy;
    cin >> dummy;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string generateAddress() {
    vector<string> locations = {
        "서울시 강남구", "서울시 강동구", "서울시 강북구", "서울시 강서구", "서울시 관악구",
        "서울시 광진구", "서울시 구로구", "서울시 금천구", "서울시 노원구", "서울시 도봉구",
        "서울시 동대문구", "서울시 동작구", "서울시 마포구", "서울시 서대문구", "서울시 서초구",
        "서울시 성동구", "서울시 성북구", "서울시 송파구", "서울시 양천구", "서울시 영등포구",
        "서울시 용산구", "서울시 은평구", "서울시 종로구", "서울시 중구", "서울시 중랑구",
        "부산시 강서구", "부산시 금정구", "부산시 기장군", "부산시 남구", "부산시 동구",
        "부산시 동래구", "부산시 부산진구", "부산시 북구", "부산시 사상구", "부산시 사하구",
        "부산시 서구", "부산시 수영구", "부산시 연제구", "부산시 영도구", "부산시 중구",
        "부산시 해운대구", "대구시 달서구", "대구시 달성군", "대구시 동구", "대구시 북구",
        "대구시 서구", "대구시 수성구", "대구시 중구", "인천시 강화군", "인천시 계양구",
        "인천시 남동구", "인천시 동구", "인천시 미추홀구", "인천시 부평구", "인천시 서구",
        "인천시 연수구", "인천시 중구", "광주시 광산구", "광주시 남구", "광주시 동구",
        "광주시 북구", "광주시 서구", "대전시 대덕구", "대전시 동구", "대전시 서구",
        "대전시 유성구", "대전시 중구", "울산시 남구", "울산시 동구", "울산시 북구",
        "울산시 중구", "세종시", "경기도 고양시 덕양구", "경기도 고양시 일산동구", "경기도 고양시 일산서구",
        "경기도 과천시", "경기도 광명시", "경기도 광주시", "경기도 구리시", "경기도 군포시",
        "경기도 김포시", "경기도 남양주시", "경기도 동두천시", "경기도 부천시 소사구", "경기도 부천시 오정구",
        "경기도 부천시 원미구", "경기도 성남시 분당구", "경기도 성남시 수정구", "경기도 성남시 중원구",
        "경기도 수원시 권선구", "경기도 수원시 영통구", "경기도 수원시 장안구", "경기도 수원시 팔달구",
        "경기도 시흥시", "경기도 안산시 단원구", "경기도 안산시 상록구", "경기도 안성시", "경기도 안양시 동안구",
        "경기도 안양시 만안구", "경기도 양주시", "경기도 오산시", "경기도 용인시 기흥구", "경기도 용인시 수지구",
        "경기도 용인시 처인구", "경기도 의왕시", "경기도 의정부시", "경기도 이천시", "경기도 파주시",
        "경기도 평택시", "경기도 포천시", "경기도 하남시", "경기도 화성시", "강원도 강릉시",
        "강원도 동해시", "강원도 삼척시", "강원도 속초시", "강원도 원주시", "강원도 춘천시",
        "강원도 태백시", "강원도 고성군", "강원도 양구군", "강원도 양양군", "강원도 영월군",
        "강원도 인제군", "강원도 정선군", "강원도 철원군", "강원도 평창군", "강원도 홍천군",
        "강원도 화천군", "강원도 횡성군", "경상남도 거제시", "경상남도 거창군", "경상남도 고성군",
        "경상남도 김해시", "경상남도 남해군", "경상남도 밀양시", "경상남도 사천시", "경상남도 산청군",
        "경상남도 양산시", "경상남도 의령군", "경상남도 진주시", "경상남도 창녕군", "경상남도 창원시 마산합포구",
        "경상남도 창원시 마산회원구", "경상남도 창원시 성산구", "경상남도 창원시 의창구", "경상남도 창원시 진해구",
        "경상남도 통영시", "경상남도 하동군", "경상남도 함안군", "경상남도 함양군", "경상남도 합천군",
        "경상북도 경산시", "경상북도 경주시", "경상북도 구미시", "경상북도 김천시", "경상북도 문경시",
        "경상북도 상주시", "경상북도 안동시", "경상북도 영덕군", "경상북도 영양군", "경상북도 영주시",
        "경상북도 영천시", "경상북도 예천군", "경상북도 울릉군", "경상북도 울진군", "경상북도 의성군",
        "경상북도 청도군", "경상북도 청송군", "경상북도 칠곡군", "경상북도 포항시 남구", "경상북도 포항시 북구",
        "전라남도 강진군", "전라남도 고흥군", "전라남도 곡성군", "전라남도 광양시", "전라남도 구례군",
        "전라남도 나주시", "전라남도 담양군", "전라남도 목포시", "전라남도 무안군", "전라남도 보성군",
        "전라남도 순천시", "전라남도 신안군", "전라남도 여수시", "전라남도 영광군", "전라남도 영암군",
        "전라남도 완도군", "전라남도 장성군", "전라남도 장흥군", "전라남도 진도군", "전라남도 함평군",
        "전라남도 해남군", "전라남도 화순군", "전라북도 고창군", "전라북도 군산시", "전라북도 김제시",
        "전라북도 남원시", "전라북도 익산시", "전라북도 전주시 덕진구", "전라북도 전주시 완산구",
        "전라북도 정읍시", "전라북도 진안군", "제주특별자치도 제주시", "제주특별자치도 서귀포시"
    };

    return locations[rand() % locations.size()];
}

string generateKoreanName() {
    vector<string> lastNames = {
        "김", "이", "박", "최", "정", "조", "강", "윤", "장", "임", "한", "오", "서", "신",
        "권", "황", "안", "송", "류", "홍", "전", "고", "문", "양", "손", "배", "백", "허", "유", "남", "노", "심", "하"
    };

    vector<string> firstNames = {
        "서준", "하윤", "도윤", "지후", "지우", "하린", "수아", "시우", "예준", "유주",
        "하늘", "예린", "은우", "유나", "지원", "소율", "지안", "연우", "민재", "채원",
        "세아", "하은", "하람", "이안", "지유", "채윤", "승우", "가은", "예나", "준호",
        "영희", "철수", "순이", "말숙", "명자", "춘자", "복자", "영자", "순자", "옥자",
        "병수", "기철", "영수", "춘호", "영호", "정숙", "상순", "만수", "동수", "갑순",
        "금희", "말자", "영길", "말선", "수남", "종철", "춘복", "희수", "기영", "진숙",
        "루나", "하이", "민하", "태하", "주하", "예하", "라온", "서이", "누리", "우주"
    };

    return lastNames[rand() % lastNames.size()] + firstNames[rand() % firstNames.size()];
}

string generatePhoneNumber() {
    int second = rand() % 9000 + 1000;
    int third = rand() % 9000 + 1000;
    return "010-" + to_string(second) + "-" + to_string(third);
}

string generateHobby() {
    vector<string> hobbies = {
        // 전통적/일반적 취미
        "독서", "영화 감상", "음악 감상", "등산", "수영", "요리", "뜨개질", "일기 쓰기",
        "산책", "글쓰기", "자전거 타기", "사진 찍기", "드로잉", "캘리그라피",

        // 실내 활동
        "보드게임", "웹서핑", "넷플릭스 보기", "유튜브 시청", "퍼즐 맞추기", "인형 만들기",
        "비디오 게임", "코딩", "프라모델 조립", "명상", "피아노 연주", "악기 배우기",

        // 야외 활동
        "캠핑", "낚시", "등산", "러닝", "스쿠버다이빙", "패러글라이딩", "서핑", "도보 여행",
        "봉사활동", "플로깅", "자연 관찰", "도시 탐방", "농촌 체험", "야경 촬영",

        // 트렌디하고 사회적인 취미
        "카페 투어", "맛집 탐방", "전시회 관람", "플리마켓 참여", "뮤지컬 관람",
        "댄스 클래스", "필라테스", "요가", "헬스", "복싱", "크로스핏", "클라이밍",
        "스포츠 관람", "펫과 놀기", "반려동물 산책", "베이킹", "인테리어 꾸미기",

        // 혼자서 하는 마이너/개성 취미
        "디지털 드로잉", "모형 수집", "책 큐레이션", "중고 거래 탐색", "SNS 운영",
        "일본어 공부", "별자리 관찰", "타로카드 공부", "식물 키우기", "커피 핸드드립"
    };

    return hobbies[rand() % hobbies.size()];
}

class Client {
public:
    int number;
    string id;
    string pw;
    string name;
    string hobby;
    string phonenum;
    string address;
};

class ClientManager {
public:
    vector<Client> clientVector;

    ClientManager() {
        // 기존 초기화 코드 동일
        Client c1;
        c1.number = 1;
        c1.id = "test-01";
        c1.pw = "password-01";
        c1.name = generateKoreanName();
        c1.hobby = generateHobby();
        c1.address = generateAddress();
        c1.phonenum = generatePhoneNumber();

        Client c2;
        c2.number = 2;
        c2.id = "test-02";
        c2.pw = "password-02";
        c2.name = generateKoreanName();
        c2.hobby = generateHobby();
        c2.address = generateAddress();
        c2.phonenum = generatePhoneNumber();

        clientVector.push_back(c1);
        clientVector.push_back(c2);
    }

    // 클라이언트 출력 함수 공통화
    void printClient(const Client& c) const {
        cout << "number: " << c.number << endl;
        cout << "id: " << c.id << endl;
        cout << "pw: " << c.pw << endl;
        cout << "name: " << c.name << endl;
        cout << "address: " << c.address << endl;
        cout << "phone: " << c.phonenum << endl;
        cout << "hobby: " << c.hobby << endl;
        cout << "-----------------------------" << endl;
    }

    void displayClient() {
        system("cls");
        cout << "클라이언트 목록" << endl;
        cout << "-----------------------------" << endl;
        for (const auto& c : clientVector) {
            printClient(c);
        }
        waitForInput();
    }

    void save2csv() {
        ofstream outfile("client.csv");
        outfile << "number,id,pw,name,address,phone,hobby\n";
        for (const auto& c : clientVector) {
            outfile << c.number << "," << c.id << "," << c.pw << "," << c.name << "," << c.address << "," << c.phonenum << "," << c.hobby << "\n";
        }
        outfile.close();

        cout << endl << "----------------------------" << endl << endl;
        cout << "CSV파일이 폴더 내 client.csv로 성공적으로 저장되었습니다." << endl;
        waitForInput();
    }

    void read4csv() {
        ifstream inFile("client.csv");
        if (!inFile) {
            cerr << "client.csv 파일을 열 수 없습니다." << endl;
            waitForInput();
            return;
        }

        clientVector.clear();
        string line;
        bool isFirstline = true;

        while (getline(inFile, line)) {
            if (isFirstline) {
                isFirstline = false;
                continue;
            }

            stringstream ss(line);
            string numstr, id, pw, name, address, phonenum, hobby;

            getline(ss, numstr, ',');
            getline(ss, id, ',');
            getline(ss, pw, ',');
            getline(ss, name, ',');
            getline(ss, address, ',');
            getline(ss, phonenum, ',');
            getline(ss, hobby);

            if (numstr.empty()) continue; // 빈 줄 방지

            Client c;
            try {
                c.number = stoi(numstr);
            }
            catch (...) {
                continue; // 숫자 변환 실패 시 건너뜀
            }
            c.id = id;
            c.pw = pw;
            c.name = name;
            c.address = address;
            c.phonenum = phonenum;
            c.hobby = hobby;

            clientVector.push_back(c);
        }
        inFile.close();

        cout << endl << "----------------------------" << endl << endl;
        cout << "CSV파일이 폴더 내 client.csv로부터 성공적으로 불러왔습니다." << endl;
        waitForInput();
    }

    void addOneClient(int count) {
        Client tempclient;
        string number;

        cout << "클라이언트 추가 (" << count << "명째)" << endl << "-----------------------------" << endl;

        while (true) {
            cout << "번호 입력: ";
            getline(cin, number);
            try {
                tempclient.number = stoi(number);
                break; // 정상 입력 시 루프 탈출
            }
            catch (...) {
                cerr << "유효한 숫자가 아닙니다. 다시 입력해주세요.\n";
            }
        }

        cout << "ID 입력: ";
        getline(cin, tempclient.id);

        cout << "PW 입력: ";
        getline(cin, tempclient.pw);

        tempclient.name = generateKoreanName();
        cout << "Name 생성: " << tempclient.name << endl;

        tempclient.address = generateAddress();
        cout << "Address 생성: " << tempclient.address << endl;

        tempclient.phonenum = generatePhoneNumber();
        cout << "Phone 생성: " << tempclient.phonenum << endl;

        tempclient.hobby = generateHobby();
        cout << "Hobby 생성: " << tempclient.hobby << endl;

        clientVector.push_back(tempclient);

        waitForInputWithMessage();
    }

    void addClient5() {
        system("cls");
        for (int i = 1; i <= 5; ++i) {
            addOneClient(i);
        }
        cout << "-----------------------------" << endl
            << "클라이언트 추가 (5명)이 완료되었습니다." << endl << endl;
        waitForInput();
    }

    void deleteClient() {
        system("cls");
        cout << "클라이언트 삭제" << endl << "-----------------------------" << endl;
        cout << "삭제할 클라이언트의 번호를 입력하세요: ";

        string input;
        getline(cin, input);

        int delNumber;
        try {
            delNumber = stoi(input);
        }
        catch (...) {
            cerr << "유효한 숫자가 아닙니다." << endl;
            waitForInput();
            return;
        }

        bool found = false;
        for (auto it = clientVector.begin(); it != clientVector.end(); ++it) {
            if (it->number == delNumber) {
                clientVector.erase(it);
                found = true;
                cout << endl << "번호 " << delNumber << "번 클라이언트가 삭제되었습니다." << endl;
                break;
            }
        }

        if (!found) {
            cout << "해당 번호의 클라이언트를 찾을 수 없습니다." << endl;
        }

        waitForInput();
    }

    void findClient() {
        system("cls");
        cout << "클라이언트 검색" << endl << "-----------------------------" << endl;
        cout << "검색할 클라이언트의 번호를 입력하세요: ";

        string input;
        getline(cin, input);

        int searchNumber;
        try {
            searchNumber = stoi(input);
        }
        catch (...) {
            cerr << endl << "유효한 숫자가 아닙니다." << endl;
            waitForInput();
            return;
        }

        bool found = false;
        for (const auto& c : clientVector) {
            if (c.number == searchNumber) {
                printClient(c);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << endl << "해당 번호의 클라이언트를 찾을 수 없습니다." << endl;
        }

        waitForInput();
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    ClientManager clientMgr;
    int choice = 0;

    while (true) {
        system("cls");
        cout << "=== 메인 메뉴 ===" << endl;
        cout << "1. 클라이언트 조회" << endl;
        cout << "2. 클라이언트 추가" << endl;
        cout << "3. 클라이언트 5명 추가" << endl;
        cout << "4. 클라이언트 삭제" << endl;
        cout << "5. 클라이언트 검색" << endl;
        cout << "6. CSV 저장" << endl;
        cout << "7. CSV 불러오기" << endl;
        cout << "8. 종료" << endl;
        cout << "번호를 입력하세요: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 정리

        switch (choice) {
        case 1:
            clientMgr.displayClient();
            break;
        case 2:
            system("cls");
            clientMgr.addOneClient(1);
            break;
        case 3:
            clientMgr.addClient5();
            break;
        case 4:
            clientMgr.deleteClient();
            break;
        case 5:
            clientMgr.findClient();
            break;
        case 6:
            clientMgr.save2csv();
            break;
        case 7:
            clientMgr.read4csv();
            break;
        case 8:
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        default:
            cout << "올바른 번호를 입력하세요." << endl;
            waitForInput();
            break;
        }
    }
}
