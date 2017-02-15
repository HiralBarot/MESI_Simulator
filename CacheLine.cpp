#include <assert.h>
#include "CacheLine.h"

bool CacheLine::isValidMESI(unsigned int value) {
    if (value == MODIFIED) {
        return 1;
    } else if (value == EXCLUSIVE) {
        return 1;
    } else if (value == SHARED) {
        return 1;
    } else if (value == INVALID) {
        return 1;
    } else {
        return 0;
    }
}
    
void CacheLine::setMESI(unsigned int value) {
    assert(isValidMESI(value));
    mesi_bits = value;
}

unsigned int CacheLine::getMESI() {
    return mesi_bits;
}

bool CacheLine::isExclusive() {
    return (getMESI() == EXCLUSIVE);
}

bool CacheLine::isModified() {
    return (getMESI() == MODIFIED);
}

bool CacheLine::isShared() {
    return (getMESI() == SHARED);
}

bool CacheLine::isInvalid() {
    return (getMESI() == INVALID);
}

unsigned int CacheLine::getLineNumber() {
    return lineNum;
}

unsigned int CacheLine::getTag() {
    return tag;
}

void CacheLine::setTag (unsigned int t) {
    tag = tagMask & t;
}

unsigned int CacheLine::getLRU () {
    return lru_bits;
}

void CacheLine::setLRU (unsigned int l) {
    lru_bits = lruMask & l;
}

bool CacheLine::isDirty () {
    return dirty_bit;
}

bool CacheLine::isValid () {
    return valid_bit;
}

void CacheLine::setDirty (bool d) {
    dirty_bit = d;   
}

void CacheLine::setValid (bool v) {
    valid_bit = v;
}

bool CacheLine::tagMatches (unsigned int tag) {
    return (tag & tagMask) == getTag();
}