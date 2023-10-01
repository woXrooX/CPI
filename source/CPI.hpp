#ifndef CPI_HPP
#define CPI_HPP

#include <string>

namespace woXrooX{

	class CPI{
	public:
		static std::string bridge(const std::string& data){
			const std::string prepared = "python3 source/CPI.py '" +data+ "'";

			char buffer[128];

			std::string response = "";

			FILE* pipe = popen(prepared.c_str(), "r");

			if(!pipe) return "Error!";

			try{
				while(fgets(buffer, sizeof(buffer), pipe) != NULL) response += buffer;
			}catch(...){
				pclose(pipe);
				return "Error!";
			}

			pclose(pipe);
			return response;
		}

	};
}

#endif
