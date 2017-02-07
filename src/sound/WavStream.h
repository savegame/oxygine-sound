#pragma once
#include "SoundStream.h"
#include "core/file.h"
#include "MemoryStream.h"

namespace oxygine
{
    class WavStream : public SoundStream
    {
    public:
        WavStream();
        ~WavStream();

        void init(file::handle fh, bool close);
        void init(const char* name);
        void init(const void* data, size_t size);

        int  decodeNextBlock(bool looped, void* data, int bufferSize) override;
        void decodeAll(void* data, int bufferSize) override;

        void reset() override;
        void setPosition(int tm) override;
        int getPosition() const override;

    protected:
        void release();

        file::handle _fh;
        fileRMem _memfile;

        int _dataSize;
        int _dataPos;
        bool _close;
    };
}