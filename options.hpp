//
// options.hpp
// ~~~~~~~~~~~
//
// Copyright (c) 2011 Jack (jack.wgm@gmail.com)
//

#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#pragma once

#include <map>

namespace avhttp {

// 选项表.
typedef std::map<std::string, std::string> option_item;

class option
{
public:
	option() {}
	~option() {}

public:

	// 添加选项, 由key/value形式添加.
	void insert(const std::string &key, const std::string &val)
	{
		m_opts[key] = val;
	}

	// 删除选项.
	void remove(const std::string &key)
	{
		option_item::iterator f = m_opts.find(key);
		if (f != m_opts.end())
			m_opts.erase(f);
	}

	// 清空.
	void clear()
	{
		m_opts.clear();
	}

	// 返回所有option.
	option_item& option_all()
	{
		return m_opts;
	}

protected:
	option_item m_opts;
};

// 请求时的http选项.
// 以下选项为必http必选项.
// request_method, 取值 "GET/POST/HEAD", 默认为"GET".
// Host, 取值为http服务器, 默认为http服务器.
// Accept, 取值任意, 默认为"*/*".
typedef option request_opts;
typedef option response_opts;	// http服务器返回的http选项.

}

#endif // __OPTIONS_H__
