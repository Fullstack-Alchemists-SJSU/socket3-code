#ifndef SESSION_HANDLER
#define SESSION_HANDLER

#include <memory>
#include <string>
#include <cstring>
#include <thread>
#include <vector>
#include <time.h>

using namespace std;

class Session{

  public:
    int descriptor;
    unsigned long int count;
    time_t lastTime;

  public:
    Session(): descriptor(-1), count(0) {}
    Session(int descriptor, unsigned long count): descriptor(descriptor), count(count){}
    Session(const Session& s);

    void increment(unsigned long by = 1);
    void updateLastTime();
    Session& operator=(const Session& from);
};

class SessionHandler{

  private:
    static const int sDebug = 1;

    bool isActive;
    unsigned int refreshRate;
    shared_ptr<thread> sessionThread;
    vector<Session> sessions;

    void run();
    void optimizeAndWait(bool idle);
    bool cycle();
    vector<string> splitter(Session& s, const char* raw, int length);

  public:
    SessionHandler();
    SessionHandler(const SessionHandler& handler) = delete;
    virtual ~SessionHandler(){
      stop();
    }

    void start();
    void stop();
    void addSession(int socketDescriptor);
    virtual void process(const vector<string>& results);
};

#endif // !SESSION_HANDLER
