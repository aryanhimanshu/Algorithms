defmodule LinearSearch do
  def search([], _target), do: false
  def search([head  | _target], target) when head == target, do: true
  def search([_head | tail], target), do: search(tail, target)
end

items = [5, 10, 34, 18, 6, 7, 45, 67]
target = 10
if LinearSearch.search(items, target) do
  IO.puts "Found"
else
  IO.puts "Not found"
end


