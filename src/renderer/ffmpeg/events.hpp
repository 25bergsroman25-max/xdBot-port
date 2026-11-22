#pragma once

#include "render_settings.hpp"
#include <Geode/Geode.hpp>
#include <filesystem>
#include <vector>
#include <string>

namespace ffmpeg::events {
namespace impl {
    struct Dummy {};
}

class Recorder {
public:
    Recorder() {
        m_ptr = nullptr;
    }

    ~Recorder() = default;

    bool isValid() const { return m_ptr != nullptr; }

    geode::Result<> init(RenderSettings const& settings) {
        return geode::Err("FFmpeg event API is not supported on Geode v6");
    }

    void stop() {}

    geode::Result<> writeFrame(const std::vector<uint8_t>& frameData) {
        return geode::Err("Failed to call writeFrame function.");
    }

    static std::vector<std::string> getAvailableCodecs() {
        return {};
    }

private:
    impl::Dummy* m_ptr = nullptr;
};

class AudioMixer {
public:
    AudioMixer() = delete;

    static geode::Result<> mixVideoAudio(
        std::filesystem::path const& videoFile,
        std::filesystem::path const& audioFile,
        std::filesystem::path const& outputMp4File
    ) {
        return geode::Err("FFmpeg event API is not supported on Geode v6");
    }

    static geode::Result<> mixVideoRaw(
        std::filesystem::path const& videoFile,
        const std::vector<float>& raw,
        std::filesystem::path const& outputMp4File
    ) {
        return geode::Err("FFmpeg event API is not supported on Geode v6");
    }
};

}
