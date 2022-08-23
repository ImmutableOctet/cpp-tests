#include <iostream>
#include <streambuf>
#include <array>

#include <string_view>

template <size_t fixed_size, typename byte_type=char>
struct fixed_stream_buffer : public std::streambuf // std::basic_streambuf<byte_type, std::char_traits<byte_type>>
{
	protected:
		using byte_t = byte_type;
		using array_type = std::array<byte_t, fixed_size>;

		array_type _data;
	public:
		constexpr fixed_stream_buffer()
		{
			auto* p = _data.data();

			setp(p, (p + fixed_size));
		}

		constexpr size_t bytes_written() const
		{
			return (pptr() - pbase());
		}

		constexpr size_t size() const { return fixed_size; }

		constexpr array_type& data() { return _data; }
		constexpr const array_type& data() const { return _data; }
};

int main()
{
	fixed_stream_buffer<128> buffer;

	std::ostream out(&buffer);

	out << 123.2f << std::endl;
	//out.flush(); // Already handled by `std::endl`.

	std::cout << "Number of bytes written: " << buffer.bytes_written() << '\n';
	std::cout << "Content: " << std::string_view(buffer.data().data(), buffer.bytes_written()) << std::endl;

	std::cin.get();

	return 0;
}
