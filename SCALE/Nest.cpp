
#include "SCALE/Nest.h"
#include "base/XPRINTF.h"

namespace SCALE
{

    Nest::Nest(const char* const name) :
        SRTX::Task(name),
        m_scriptname(NULL),
        m_scale(Scale_if::get_instance())
    {
    }


    bool Nest::init()
    {
        return true;
    }


    bool Nest::execute()
    {
        fprintf(stderr, "Running the nest\n");

        if(NULL == m_scriptname)
        {
            return false;
        }

        /* Execute the main script that drives the simulation.
         */
        if(false == m_scale.run_script(m_scriptname))
        {
            EPRINTF("Failed executing script: %s\n", m_scriptname);
            return false;
        }

        return false;
    }


    void Nest::terminate()
    {
    }

} // namespace
