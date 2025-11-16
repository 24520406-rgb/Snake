#pragma region GameFunction
// Draw snakeboard with WIDTH and HEIGHT was set
void drawBox()
{
    // Vòng lặp này vẽ biên trên cùng của hộp (dùng ký tự '=')
	for (size_t i = 0; i < WIDTH; i++)
		cout << '=';
    
    // Di chuyển con trỏ xuống hàng cuối cùng (Hàng HEIGHT)
	gotoxy(0, HEIGHT);
    
    // Vòng lặp này vẽ biên dưới cùng của hộp (dùng ký tự '=')
	for (size_t i = 0; i < WIDTH; i++)
		cout << '=';
    
    // Vòng lặp này vẽ biên bên trái, từ hàng 1 đến HEIGHT-1 (dùng ký tự '|')
	for (size_t i = 1; i < HEIGHT; i++)
	{
		gotoxy(0, i); // Di chuyển con trỏ đến cột 0 (biên trái)
		cout << '|';
	}
    
    // Vòng lặp này vẽ biên bên phải, từ hàng 1 đến HEIGHT-1 (dùng ký tự '|')
	for (size_t i = 1; i < HEIGHT; i++)
	{
		gotoxy(WIDTH, i); // Di chuyển con trỏ đến cột WIDTH (biên phải)
		cout << '|';
	}
}

// Check if the snake hit the wall
bool isHitWall()
{
    // Trả về TRUE nếu đầu rắn (snake[0]) chạm vào bất kỳ biên nào:
    // Cột 0 (trên cùng), Hàng 0 (trái), Cột WIDTH (dưới cùng), Hàng HEIGHT (phải).
	return snake[0].x == 0 || snake[0].y == 0 || snake[0].x == WIDTH || snake[0].y == HEIGHT;
}

// Generate apple on the board
void genApple()
{
    // Khởi tạo hạt giống cho hàm rand() dựa trên thời gian hiện tại
    // Điều này giúp đảm bảo táo xuất hiện ở vị trí ngẫu nhiên mỗi lần chạy.
	srand(time(0));
    
    // Tạo tọa độ X ngẫu nhiên (từ 1 đến WIDTH - 1 để tránh biên)
	int x = rand() % (WIDTH - 1) + 1;
    
    // Tạo tọa độ Y ngẫu nhiên (từ 1 đến HEIGHT - 1 để tránh biên)
	int y = rand() % (HEIGHT - 1) + 1;
    
    // Lưu tọa độ ngẫu nhiên vào biến apple
	apple = {
		x,
		y,
	};
    
    // Di chuyển con trỏ đến vị trí táo mới
	gotoxy(x, y);
    
    // In ra ký tự đại diện cho Táo (thường là APPLE)
	cout << APPLE;
}

// Check if the snake ate apple
bool isAteApple()
{
    // Trả về TRUE nếu tọa độ X VÀ Y của đầu rắn (snake[0]) trùng với tọa độ của táo (apple)
	return snake[0].x == apple.x && snake[0].y == apple.y;
}

// Show score on right side of the board
void displayScore()
{
    // Di chuyển con trỏ đến vị trí hiển thị điểm (Cột WIDTH + 5, Hàng 2)
	gotoxy(WIDTH + 5, 2);
    
    // In ra chuỗi "Your score: " cùng với giá trị hiện tại của biến 'score'
	cout << "Your score: " << score;
}