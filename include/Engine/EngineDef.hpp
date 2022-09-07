/* 
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** define for the engine
*/

#ifndef ENGINE_DEF_H_
#define ENGINE_DEF_H_

#define MAX_COMPONENTS 100
#define MAX_ENTITY 1000
#define SCREENWIDTH 800
#define SCREENHEIGHT 450
using Entity = std::uint32_t;
using ComponentType = std::uint32_t;
using EventId = std::uint32_t;

#define CHECK_OP(val1,op,val2)						\
  if(!(val1 op val2) std::out << "CHECK FAIL:" << val1 << " " << op << " " << val2 << std::endl;

#define LOG_ERROR(msg) std::cerr << msg <<std::endl;

#define LOG_DEBUG(msg) std::cout << msg << std::endl;



//#define	ENGINE_LOG

#ifdef ENGINE_LOG
#define ENTITY_LOG true
#define SYSTEM_LOG true
#define COMPONENT_LOG true
#define WORLD_LOG true
#define LOG_MAP(map) for (const auto& [key, value] : map) { std::cout << '[' << key << "] = " << value << "; ";}std::cout << std::endl;

#else
#define ENTITY_LOG false
#define SYSTEM_LOG false
#define COMPONENT_LOG false
#define WORLD_LOG false
#define LOG_MAP(map)
#endif 

#if WORLD_LOG == true
#define INTER_LOG(msg) LOG_DEBUG(msg)
#define INTER_VAL(val) LOG_DEBUG(val)
#define INTER_DISP(msg,val) LOG_DEBUG(msg + val)
#else
#define INTER_LOG(msg)
#define INTER_VAL(val)
#define INTER_DISP(msg,val)
#endif 

#if SYSTEM_LOG == true
#define SYS_LOG(msg) LOG_DEBUG(msg)
#define SYS_VAL(val) LOG_DEBUG(val)
#define SYS_DISP(msg,val) LOG_DEBUG(msg) LOG_DEBUG(val)
#define SYS_MAP(msg) LOG_MAP(msg)
#else
#define SYS_LOG(msg)
#define SYS_VAL(val)
#define SYS_DISP(msg,val) 
#define SYS_MAP(msg)
#endif 

#if COMPONENT_LOG == true
#define COMP_LOG(msg) LOG_DEBUG(msg)
#define COMP_VAL(val) LOG_DEBUG(val)
#define COMP_DISP(msg,val) LOG_DEBUG(msg) LOG_DEBUG(val)
#define COMP_MAP(msg) LOG_MAP(msg)
#else
#define COMP_LOG(msg)
#define COMP_VAL(val))
#define COMP_DISP(msg,val)
#define COMP_MAP(msg)
#endif 

#if ENTITY_LOG == true
#define ENTI_LOG(msg) LOG_DEBUG(msg)
#define ENTI_VAL(val) LOG_DEBUG(val)
#define ENTI_DISP(msg,val) LOG_DEBUG(msg) LOG_DEBUG(val)
#else
#define ENTI_LOG(msg) 
#define ENTI_VAL(val)
#define ENTI_DISP(msg,val)
#endif

#include "IndieStudio.hpp"
#define METHOD_LISTENER(EventType, Listener) EventType, std::bind(&Listener, this, std::placeholders::_1)
#define FUNCTION_LISTENER(EventType, Listener) EventType, std::bind(&Listener, std::placeholders::_1)





#endif
