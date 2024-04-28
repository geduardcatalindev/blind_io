#pragma once

#include <cstdint>
#include <string>

#include <Windows.h>

#include "auto_release.h"

namespace bio
{

/**
 * This class represents a view onto a running process and provides methods for interacting with it.
 */
class Process
{
  public:
    /**
     * Construct a new Process object from a pid.
     *
     * @param pid
     *   Pid of process.
     */
    Process(std::uint32_t pid);

    /**
     * Get process pid.
     *
     * @returns
     *   Process pid.
     */
    std::uint32_t pid() const;

    /**
     * Get process name.
     *
     * @returns
     *   Process name.
     */
    std::string name() const;

  private:
    /** Process pid. */
    std::uint32_t pid_;

    /** Win32 windows handle to process. */
    AutoRelease<HANDLE> handle_;
};

}
