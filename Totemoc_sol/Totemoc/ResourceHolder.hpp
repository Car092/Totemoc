#ifndef TOTEMOC_RESOURCEHOLDER_HPP
#define TOTEMOC_RESOURCEHOLDER_HPP

#include <string>
#include <map>
#include <memory>
#include <cassert>

template<typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void load(Identifier id, const std::string& filename);
	template<typename Parameter>
	void load(Identifier id, const std::string& filename, Parameter secondParam);
	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;
	void insertResource(Identifier id, std::unique_ptr<Resource> resource);

private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "ResourceHolder.inl"

#endif //TOTEMOC_RESOURCEHOLDER_HPP