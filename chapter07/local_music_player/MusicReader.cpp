#include "MusicReader.hpp"

MusicReader::MusicReader(){
}

bool MusicReader::open(const QString &) {
    return false;
}

std::shared_ptr< const MusicInformation >
MusicReader::information() const{
    return {};
}

bool MusicReader::seek(std::int64_t /*ms*/){
    return false;
}

void MusicReader::close(){
}

void MusicReader::pppDestoryThisPrivate(){
}

MusicReader::~MusicReader(){
    pppDestoryThisPrivate();
}

void MusicReader::start(std::int64_t  ) {

}

std::shared_ptr< const MusicFrame > MusicReader::readNext() {
    return {};
}

/**/

