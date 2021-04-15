#ifndef	STUPID_JSON_H_
#define STUPID_JSON_H_

#include <string>

namespace stupid
{
    namespace stupid_json 
    {
        template <typename ...kvs>
        void build_json(kvs...);

        template <typename value, typename ...another_kvs>
        void build_json(std::string& trunk, const std::string& key, const value& v, another_kvs... ano_kvs)
        {
            build_json(trunk.append("\"").append(key).append(":\"").append(std::to_string(v)).append("\""), ano_kvs...);
        }

        template <typename ...another_kvs>
        void build_json(std::string& trunk, const std::string& key, std::string& v, another_kvs... ano_kvs)
        {
            build_json(trunk.append("\"").append(key).append(":\"").append(v).append("\""), ano_kvs...);
        }

        template <typename ...another_kvs>
        void build_json(std::string& trunk, const std::string& key, const char* v, another_kvs... ano_kvs)
        {
            build_json(trunk.append("\"").append(key).append(":\"").append(v).append("\""), ano_kvs...);
        }

        template <typename value>
        void build_json(std::string& trunk, const std::string& key, const value& v)
        {
            trunk.append("\"").append(key).append(":\"").append(std::to_string(v)).append("\"");
        }

        template <>
        void build_json(std::string& trunk, const std::string& key, const std::string& v)
        {
            trunk.append("\"").append(key).append(":\"").append(v).append("\"");
        }

        template <>
        void build_json(std::string& trunk, const std::string& key, const char* v)
        {
            trunk.append("\"").append(key).append(":\"").append(v).append("\"");
        }

        template <>
        void build_json(std::string& trunk) { return; }
    }
}


#endif 
